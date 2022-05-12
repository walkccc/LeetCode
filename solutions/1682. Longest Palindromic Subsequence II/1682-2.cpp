class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    // dp[i][j][k] := LPS's length in s[i..j] w/ previous char = 'a' + k
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(27)));

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i)
        for (int k = 0; k <= 26; ++k) {
          const int j = i + d;
          if (s[i] == s[j] && s[i] != 'a' + k)
            dp[i][j][k] = dp[i + 1][j - 1][s[i] - 'a'] + 2;
          else
            dp[i][j][k] = max(dp[i + 1][j][k], dp[i][j - 1][k]);
        }

    return dp[0][n - 1][26];
  }
};
