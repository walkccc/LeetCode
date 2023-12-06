class Solution {
  public int stoneGameII(int[] piles) {
    final int n = piles.length;
    // dp[i][j] := the maximum number of stones Alice can get with piles[i:] and M = j
    dp = new int[n][n];
    // suffixSum[i] := the sum of piles[i:]
    suffixSum = piles.clone();

    for (int i = n - 2; i >= 0; --i)
      suffixSum[i] += suffixSum[i + 1];

    return stoneGameII(0, 1);
  }

  private int[][] dp;
  private int[] suffixSum;

  private int stoneGameII(int i, int M) {
    if (i + 2 * M >= dp.length)
      return suffixSum[i];
    if (dp[i][M] > 0)
      return dp[i][M];

    int opponent = suffixSum[i];

    for (int X = 1; X <= 2 * M; ++X)
      opponent = Math.min(opponent, stoneGameII(i + X, Math.max(M, X)));

    return dp[i][M] = suffixSum[i] - opponent;
  }
}
