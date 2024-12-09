class Solution {
  public boolean canCross(int[] stones) {
    final int n = stones.length;
    // dp[i][j] := 1 if a frog can make a size j jump to stones[i]
    int[][] dp = new int[n][n + 1];
    dp[0][0] = 1;

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        final int k = stones[i] - stones[j];
        if (k > n)
          continue;
        for (final int x : new int[] {k - 1, k, k + 1})
          if (0 <= x && x <= n)
            dp[i][k] |= dp[j][x];
      }

    return Arrays.stream(dp[n - 1]).anyMatch(a -> a == 1);
  }
}
