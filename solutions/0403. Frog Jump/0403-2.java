class Solution {
  public boolean canCross(int[] stones) {
    final int n = stones.length;
    // dp[i][j] := 1 if a frog can make a size j jump from stones[i]
    int[][] dp = new int[n][n + 1];
    dp[0][1] = 1;

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        final int k = stones[i] - stones[j];
        if (k <= n && dp[j][k] == 1) {
          dp[i][k - 1] = 1;
          dp[i][k] = 1;
          dp[i][k + 1] = 1;
        }
      }

    return Arrays.stream(dp[n - 1]).anyMatch(a -> a == 1);
  }
}
