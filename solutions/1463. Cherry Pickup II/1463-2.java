class Solution {
  public int cherryPickup(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[x][y1][y2] := max cherries we can collect w/
    // Robot #1 on (x, y1) and Robot #2 on (x, y2) first
    int[][][] dp = new int[m + 1][n][n];

    for (int x = m - 1; x >= 0; --x)
      for (int y1 = 0; y1 < n; ++y1)
        for (int y2 = 0; y2 < n; ++y2) {
          final int currRow = grid[x][y1] + (y1 == y2 ? 0 : 1) * grid[x][y2];
          for (int d1 = Math.max(0, y1 - 1); d1 < Math.min(n, y1 + 2); ++d1)
            for (int d2 = Math.max(0, y2 - 1); d2 < Math.min(n, y2 + 2); ++d2)
              dp[x][y1][y2] = Math.max(dp[x][y1][y2], currRow + dp[x + 1][d1][d2]);
        }

    return dp[0][0][n - 1];
  }
}
