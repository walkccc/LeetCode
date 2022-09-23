class Solution {
  public int mergeStones(int[] stones, int K) {
    final int n = stones.length;
    if ((n - 1) % (K - 1) != 0)
      return -1;

    this.K = K;

    // dp[i][j] := min cost to merge stones[i..j]
    dp = new int[n][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, kMax));
    prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];

    final int cost = mergeStones(stones, 0, n - 1);
    return cost == kMax ? -1 : cost;
  }

  private static final int kMax = 1_000_000_000;
  private int K;
  private int[][] dp;
  private int[] prefix;

  private int mergeStones(final int[] stones, int i, int j) {
    if (j - i + 1 < K)
      return 0;
    if (dp[i][j] != kMax)
      return dp[i][j];

    for (int m = i; m < j; m += K - 1)
      dp[i][j] = Math.min(dp[i][j], mergeStones(stones, i, m) + mergeStones(stones, m + 1, j));
    if ((j - i) % (K - 1) == 0)
      dp[i][j] += prefix[j + 1] - prefix[i];

    return dp[i][j];
  }
}
