class Solution {
  public long maxPoints(int[][] points) {
    final int n = points[0].length;
    // dp[j] := max # points you can have if points[i][j] is the most recent cell you picked
    long[] dp = new long[n];

    for (int[] row : points) {
      long[] leftToRight = new long[n];
      long runningMax = 0;

      for (int j = 0; j < n; ++j) {
        runningMax = Math.max(runningMax - 1, dp[j]);
        leftToRight[j] = runningMax;
      }

      long[] rightToLeft = new long[n];
      runningMax = 0;

      for (int j = n - 1; j >= 0; --j) {
        runningMax = Math.max(runningMax - 1, dp[j]);
        rightToLeft[j] = runningMax;
      }

      for (int j = 0; j < n; ++j)
        dp[j] = Math.max(leftToRight[j], rightToLeft[j]) + row[j];
    }

    return Arrays.stream(dp).max().getAsLong();
  }
}
