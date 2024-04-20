class Solution {
 public:
  int strangePrinter(string s) {
    if (s.empty())
      return 0;

    const int n = s.size();
    // dp[i][j] := the minimum number of turns to print s[i..j]
    vector<vector<int>> dp(n, vector<int>(n, n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int j = 0; j < n; ++j)
      for (int i = j; i >= 0; --i)
        for (int k = i; k < j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - (s[k] == s[j]));

    return dp[0][n - 1];
  }
};
