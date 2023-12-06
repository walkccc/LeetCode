class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    const int wordLength = words[0].length();
    // dp[i][j] := the number of ways to form target[i..n) using word[j..n)
    dp.resize(target.length(), vector<int>(wordLength, -1));
    // counts[j] := the count map of words[i][j], where 0 <= i < |words|
    vector<vector<int>> counts(wordLength, vector<int>(26));

    for (int i = 0; i < wordLength; ++i)
      for (const string& word : words)
        ++counts[i][word[i] - 'a'];

    return numWays(target, 0, 0, counts);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<int>> dp;

  int numWays(const string& target, int i, int j,
              const vector<vector<int>>& counts) {
    if (i == target.length())
      return 1;
    if (j == counts.size())
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    return dp[i][j] = (numWays(target, i + 1, j + 1, counts) *
                           static_cast<long>(counts[j][target[i] - 'a']) +
                       numWays(target, i, j + 1, counts)) %
                      kMod;
  };
};
