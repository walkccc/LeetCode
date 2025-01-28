class Solution {
  public int minDifficulty(int[] jobDifficulty, int d) {
    final int n = jobDifficulty.length;
    if (n < d)
      return -1;

    // dp[i][k] := the minimum difficulty to schedule the first i jobs in k days
    int[][] dp = new int[n + 1][d + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE / 2));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
      for (int k = 1; k <= d; ++k) {
        // max(job[j + 1..i])
        int maxDifficulty = 0;
        for (int j = i - 1; j >= k - 1; --j) {                       // 1-based
          maxDifficulty = Math.max(maxDifficulty, jobDifficulty[j]); // 0-based
          dp[i][k] = Math.min(dp[i][k], dp[j][k - 1] + maxDifficulty);
        }
      }

    return dp[n][d];
  }
}
