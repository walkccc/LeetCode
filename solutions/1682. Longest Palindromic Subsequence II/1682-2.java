class Solution {
  public int longestPalindromeSubseq(String s) {
    final int n = s.length();
    // dp[i][j][k] := the length of LPS(s[i..j]) with the previous letter
    // (a' + k)
    int[][][] dp = new int[n][n][27];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i)
        for (int k = 0; k <= 26; ++k) {
          final int j = i + d;
          if (s.charAt(i) == s.charAt(j) && s.charAt(i) != 'a' + k)
            dp[i][j][k] = dp[i + 1][j - 1][s.charAt(i) - 'a'] + 2;
          else
            dp[i][j][k] = Math.max(dp[i + 1][j][k], dp[i][j - 1][k]);
        }

    return dp[0][n - 1][26];
  }
}
