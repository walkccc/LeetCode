class Solution {
  public int strangePrinter(String s) {
    final int n = s.length();
    // dp[i][j] := min # of turns to print s[i..j]
    dp = new int[n][n];
    return strangePrinter(s, 0, n - 1);
  }

  private int[][] dp;

  private int strangePrinter(final String s, int i, int j) {
    if (i > j)
      return 0;
    if (dp[i][j] > 0)
      return dp[i][j];

    // print s[i]
    dp[i][j] = strangePrinter(s, i + 1, j) + 1;

    for (int k = i + 1; k <= j; ++k)
      if (s.charAt(k) == s.charAt(i))
        dp[i][j] = Math.min(dp[i][j], strangePrinter(s, i, k - 1) + strangePrinter(s, k + 1, j));

    return dp[i][j];
  }
}
