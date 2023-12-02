class Solution {
  public int stoneGameVII(int[] stones) {
    final int n = stones.length;
    // dp[i][j] := the maximum score you can get more than your opponent in stones[i..j]
    dp = new int[n][n];
    prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = stones[i] + prefix[i];

    return stoneGameVII(stones, 0, n - 1);
  }

  private int[][] dp;
  private int[] prefix;

  int stoneGameVII(int[] stones, int i, int j) {
    if (i == j)
      return 0;
    if (dp[i][j] > 0)
      return dp[i][j];

    dp[i][j] =
        Math.max(dp[i][j], Math.max(
                               // Remove stones[i], so get the sum of stones[i + 1..j]
                               prefix[j + 1] - prefix[i + 1] - stoneGameVII(stones, i + 1, j),
                               // Remove stones[j], so get the sum of stones[i..j - 1]
                               prefix[j] - prefix[i] - stoneGameVII(stones, i, j - 1)));

    return dp[i][j];
  }
}
