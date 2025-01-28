class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    // dp[i][j] := the length of LPS(s[i..j])
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        if (s[i] == s[j])
          dp[i][j] = 2 + dp[i + 1][j - 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }

    return dp[0][n - 1];
  }
};
