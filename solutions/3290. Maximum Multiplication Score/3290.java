class Solution {
  public long maxScore(int[] a, int[] b) {
    final int n = b.length;
    final long kMin = Long.MIN_VALUE / 2;
    // dp[i][j] := the maximum score by selecting 4 - i numbers from b[j..n - 1]
    // using the corresponding numbers from a[i..3]
    long[][] dp = new long[5][n + 1];

    // Run out of numbers in b but still need to select numbers from a.
    for (int i = 0; i < 4; ++i)
      dp[i][n] = kMin;

    for (int i = 3; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j)
        // Skip b[j] or pair a[i] with b[j].
        dp[i][j] = Math.max(dp[i][j + 1], a[i] * (long) b[j] + dp[i + 1][j + 1]);

    return dp[0][0] == kMin ? -1 : dp[0][0];
  }
}
