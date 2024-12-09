class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    const int m = text1.length();
    const int n = text2.length();
    // dp[i][j] := the length of LCS(text1[0..i), text2[0..j))
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dp[i + 1][j + 1] = text1[i] == text2[j]
                               ? 1 + dp[i][j]
                               : max(dp[i][j + 1], dp[i + 1][j]);

    return dp[m][n];
  }
};
