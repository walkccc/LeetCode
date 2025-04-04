class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    const int m = s1.length();
    const int n = s2.length();
    // dp[i][j] := the minimum cost to make s1[0..i) and s2[0..j) equal
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Delete s1[i - 1].
    for (int i = 1; i <= m; ++i)
      dp[i][0] = dp[i - 1][0] + s1[i - 1];

    // Delete s2[j - 1].
    for (int j = 1; j <= n; ++j)
      dp[0][j] = dp[0][j - 1] + s2[j - 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);

    return dp[m][n];
  }
};
