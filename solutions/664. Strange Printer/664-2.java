class Solution {
  public int strangePrinter(String s) {
    if (s.isEmpty())
      return 0;

    final int n = s.length();
    // dp[i][j] := the minimum number of turns to print s[i..j]
    int[][] dp = new int[n][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int j = 0; j < n; ++j)
      for (int i = j; i >= 0; --i)
        for (int k = i; k < j; ++k)
          dp[i][j] =
              Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] - (s.charAt(k) == s.charAt(j) ? 1 : 0));

    return dp[0][n - 1];
  }
}
