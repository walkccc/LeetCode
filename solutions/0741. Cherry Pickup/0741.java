class Solution {
  public int cherryPickup(int[][] grid) {
    // the problem is identical as two people start picking cherries
    // from grid[0][0] simultaneously
    n = grid.length;
    dp = new Integer[n][n][n];
    return Math.max(0, cherryPickup(grid, 0, 0, 0));
  }

  private int n;

  // dp[x1][y1][x2] := max cherries we could pick from
  // g[0][0] -> g[x1 - 1][y1 - 1] + g[0][0] -> g[x2 - 1][y2 - 1],
  // where y2 = x1 + y1 - x2 (reduce states from 4 to 3)
  private Integer[][][] dp;

  private int cherryPickup(int[][] grid, int x1, int y1, int x2) {
    final int y2 = x1 + y1 - x2;
    if (x1 == n || y1 == n || x2 == n || y2 == n)
      return -1;
    if (x1 == n - 1 && y1 == n - 1)
      return grid[x1][y1];
    if (grid[x1][y1] == -1 || grid[x2][y2] == -1)
      return -1;
    if (dp[x1][y1][x2] != null)
      return dp[x1][y1][x2];

    dp[x1][y1][x2] = Math.max(
        Math.max(cherryPickup(grid, x1 + 1, y1, x2), cherryPickup(grid, x1 + 1, y1, x2 + 1)),
        Math.max(cherryPickup(grid, x1, y1 + 1, x2), cherryPickup(grid, x1, y1 + 1, x2 + 1)));
    if (dp[x1][y1][x2] == -1)
      return dp[x1][y1][x2];

    dp[x1][y1][x2] += grid[x1][y1]; // do pick some cherries
    if (x1 != x2)                   // two people are on different grids
      dp[x1][y1][x2] += grid[x2][y2];

    return dp[x1][y1][x2];
  }
}
