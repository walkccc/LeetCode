class Solution {
  public int getMoneyAmount(int n) {
    // dp[i][j] := min money you need to guarantee a win of picking i..j
    int[][] dp = new int[n + 2][n + 2];

    for (int d = 1; d < n; ++d)
      for (int i = 1; i + d <= n; ++i) {
        final int j = i + d;
        dp[i][j] = Integer.MAX_VALUE;
        for (int k = i; k <= j; ++k)
          dp[i][j] = Math.min(dp[i][j], Math.max(dp[i][k - 1], dp[k + 1][j]) + k);
      }

    return dp[1][n];
  }
}
