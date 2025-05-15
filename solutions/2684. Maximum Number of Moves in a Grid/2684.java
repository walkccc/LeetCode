class Solution {
  public int maxMoves(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    // dp[i][j] := the maximum number of moves you can perform from (i, j)
    int[][] dp = new int[m][n];

    for (int j = n - 2; j >= 0; --j)
      for (int i = 0; i < m; ++i) {
        if (grid[i][j + 1] > grid[i][j])
          dp[i][j] = 1 + dp[i][j + 1];
        if (i > 0 && grid[i - 1][j + 1] > grid[i][j])
          dp[i][j] = Math.max(dp[i][j], 1 + dp[i - 1][j + 1]);
        if (i + 1 < m && grid[i + 1][j + 1] > grid[i][j])
          dp[i][j] = Math.max(dp[i][j], 1 + dp[i + 1][j + 1]);
      }

    for (int i = 0; i < m; ++i)
      ans = Math.max(ans, dp[i][0]);

    return ans;
  }
}
