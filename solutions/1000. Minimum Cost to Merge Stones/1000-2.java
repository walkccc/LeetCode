class Solution {
  public int mergeStones(int[] stones, int K) {
    final int n = stones.length;
    if ((n - 1) % (K - 1) != 0)
      return -1;

    final int kMax = 1_000_000_000;

    // dp[i][j][k] := min cost to merge stones[i..j] into k piles
    int[][][] dp = new int[n][n][K + 1];
    for (int[][] A : dp)
      Arrays.stream(A).forEach(a -> Arrays.fill(a, kMax));
    int[] prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      dp[i][i][1] = 0;

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        for (int k = 2; k <= K; ++k) // piles
          for (int m = i; m < j; m += K - 1)
            dp[i][j][k] = Math.min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
        dp[i][j][1] = dp[i][j][K] + prefix[j + 1] - prefix[i];
      }

    return dp[0][n - 1][1];
  }
}
