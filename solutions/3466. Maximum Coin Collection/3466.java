class Solution {
  public long maxCoins(int[] lane1, int[] lane2) {
    final int n = lane1.length;
    // dp[i][k] := the maximum number of coins at i-th mile with k switches
    long[][] dp = new long[n][3];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Long.MIN_VALUE));
    dp[0][0] = lane1[0];
    dp[0][1] = lane2[0];

    for (int i = 1; i < n; ++i) {
      dp[i][0] = Math.max(0, dp[i - 1][0]) + lane1[i];
      dp[i][1] = Math.max(0, Math.max(dp[i - 1][0], dp[i - 1][1])) + lane2[i];
      dp[i][2] = Math.max(dp[i - 1][1], dp[i - 1][2]) + lane1[i];
    }

    return Arrays.stream(dp).flatMapToLong(Arrays::stream).max().getAsLong();
  }
}
