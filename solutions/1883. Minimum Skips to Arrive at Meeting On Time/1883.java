class Solution {
  public int minSkips(int[] dist, int speed, int hoursBefore) {
    final double kInf = 1e7;
    final double kEps = 1e-9;
    final int n = dist.length;
    // dp[i][j] := min time w/ prev i-th road and j skips
    double[][] dp = new double[n + 1][n + 1];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, kInf));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      final double d = dist[i - 1];
      dp[i][0] = Math.ceil(dp[i - 1][0] + d / speed - kEps);
      for (int j = 1; j <= i; ++j)
        dp[i][j] =
            Math.min(dp[i - 1][j - 1] + d / speed, Math.ceil(dp[i - 1][j] + d / speed - kEps));
    }

    for (int j = 0; j <= n; ++j)
      if (dp[n][j] <= hoursBefore)
        return j;

    return -1;
  }
}
