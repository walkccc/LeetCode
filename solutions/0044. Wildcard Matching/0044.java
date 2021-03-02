class Solution {
  public boolean isMatch(String s, String p) {
    final int m = s.length();
    final int n = p.length();

    // dp[i][j] := true if s[0..i) matches p[0..j)
    boolean[][] dp = new boolean[m + 1][n + 1];
    dp[0][0] = true;

    for (int i = 0; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (p.charAt(j - 1) == '*') {
          final boolean matchEmpty = dp[i][j - 1];
          final boolean matchNew = i > 0 && dp[i - 1][j];
          dp[i][j] = matchEmpty || matchNew;
        } else {
          dp[i][j] = i > 0 && isMatch(s.charAt(i - 1), p.charAt(j - 1)) && dp[i - 1][j - 1];
        }

    return dp[m][n];
  }

  private boolean isMatch(char c1, char c2) {
    return c1 == c2 || c2 == '?';
  }
}
