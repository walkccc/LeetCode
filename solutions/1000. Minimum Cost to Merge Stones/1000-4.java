class Solution {
  public int mergeStones(int[] stones, int K) {
    final int n = stones.length;
    if ((n - 1) % (K - 1) != 0)
      return -1;

    final int kMax = 1_000_000_000;

    // dp[i][j] := the minimum cost to merge stones[i..j]
    int[][] dp = new int[n][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, kMax));
    int[] prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      dp[i][i] = 0;

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        for (int m = i; m < j; m += K - 1)
          dp[i][j] = Math.min(dp[i][j], dp[i][m] + dp[m + 1][j]);
        if (d % (K - 1) == 0)
          dp[i][j] += prefix[j + 1] - prefix[i];
      }

    return dp[0][n - 1];
  }
}
