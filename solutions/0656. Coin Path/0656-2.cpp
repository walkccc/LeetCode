class Solution {
 public:
  vector<int> cheapestJump(vector<int>& coins, int maxJump) {
    if (coins.back() == -1)
      return {};

    const int n = coins.size();
    // dp[i] := min cost to jump to n - 1 from i
    vector<int> dp(n, INT_MAX);
    vector<int> next(n, -1);

    dp.back() = coins.back();

    for (int i = n - 2; i >= 0; --i) {
      if (coins[i] == -1)
        continue;
      for (int j = i + 1; j < min(i + maxJump + 1, n); ++j) {
        if (dp[j] == INT_MAX)
          continue;
        const int cost = coins[i] + dp[j];
        if (cost < dp[i]) {
          dp[i] = cost;
          next[i] = j;
        }
      }
    }

    if (dp[0] == INT_MAX)
      return {};
    return constructPath(next, 0);
  }

 private:
  vector<int> constructPath(const vector<int>& next, int i) {
    vector<int> ans;
    while (i != -1) {
      ans.push_back(i + 1);  // 1-indexed
      i = next[i];
    }
    return ans;
  }
};
