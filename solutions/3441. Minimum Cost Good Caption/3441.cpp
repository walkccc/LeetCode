class Solution {
 public:
  string minCostGoodCaption(string caption) {
    const int n = caption.length();
    if (n < 3)
      return "";

    constexpr int kMaxCost = 1'000'000'000;
    // dp[i][j][k] := the minimum cost of caption[i..n - 1], where j is the last
    // letter used, and k is the count of consecutive letters
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(26, vector<int>(3, kMaxCost)));

    for (char c = 'a'; c <= 'z'; ++c)
      dp[n - 1][c - 'a'][0] = abs(caption[n - 1] - c);

    int minCost = kMaxCost;
    for (int i = n - 2; i >= 0; --i) {
      int newMinCost = kMaxCost;
      for (char c = 'a'; c <= 'z'; ++c) {
        const int j = c - 'a';
        const int changeCost = abs(caption[i] - c);
        dp[i][j][0] = changeCost + minCost;
        dp[i][j][1] = changeCost + dp[i + 1][j][0];
        dp[i][j][2] = changeCost + min(dp[i + 1][j][1], dp[i + 1][j][2]);
        newMinCost = min(newMinCost, dp[i][j][2]);
      }
      minCost = newMinCost;
    }

    // Reconstruct the string.
    string ans;
    int cost = kMaxCost;
    int letter = -1;

    // Find the initial best letter.
    for (int c = 25; c >= 0; --c)
      if (dp[0][c][2] <= cost) {
        letter = c;
        cost = dp[0][c][2];
      }

    // Add the initial triplet.
    cost -= appendLetter(caption, 0, 'a' + letter, ans);
    cost -= appendLetter(caption, 1, 'a' + letter, ans);
    cost -= appendLetter(caption, 2, 'a' + letter, ans);

    // Build the rest of the string.
    for (int i = 3; i < n;) {
      // Check if we should switch to a new letter.
      const int nextLetter = getNextLetter(dp, i, cost);
      if (nextLetter < letter || ranges::min(dp[i][letter]) > cost) {
        letter = nextLetter;
        cost -= appendLetter(caption, i, 'a' + letter, ans);
        cost -= appendLetter(caption, i + 1, 'a' + letter, ans);
        cost -= appendLetter(caption, i + 2, 'a' + letter, ans);
        i += 3;
      } else {
        cost -= appendLetter(caption, i, 'a' + letter, ans);
        i += 1;
      }
    }

    return ans;
  }

 private:
  int getNextLetter(const vector<vector<vector<int>>>& dp, int i, int cost) {
    int nextLetter = 26;  // invalid letter as the sentinel
    for (int c = 25; c >= 0; --c)
      if (cost == dp[i][c][2])
        nextLetter = c;
    return nextLetter;
  }

  int appendLetter(const string& caption, int i, char letter, string& ans) {
    ans += letter;
    return abs(caption[i] - letter);
  }
};
