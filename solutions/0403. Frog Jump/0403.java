class Solution {
  public boolean canCross(int[] stones) {
    final int n = stones.length;

    // dp[i][j] := true if a frog can jumps to stones[i] with j units
    boolean[][] dp = new boolean[n][n + 1];
    dp[0][1] = true;

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        final int k = stones[i] - stones[j];
        if (k <= n && dp[j][k]) {
          dp[i][k - 1] = true;
          dp[i][k] = true;
          dp[i][k + 1] = true;
        }
      }

    for (int j = 0; j <= n; ++j)
      if (dp[n - 1][j])
        return true;

    return false;
  }
}
