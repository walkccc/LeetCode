class Solution {
  public long sellingWood(int m, int n, int[][] prices) {
    // dp[i][j] := max money of cutting i x j piece of wood
    long[][] dp = new long[m + 1][n + 1];

    for (int[] p : prices)
      dp[p[0]][p[1]] = p[2];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        for (int h = 1; h <= i / 2; ++h)
          dp[i][j] = Math.max(dp[i][j], dp[h][j] + dp[i - h][j]);
        for (int w = 1; w <= j / 2; ++w)
          dp[i][j] = Math.max(dp[i][j], dp[i][w] + dp[i][j - w]);
      }

    return dp[m][n];
  }
}
