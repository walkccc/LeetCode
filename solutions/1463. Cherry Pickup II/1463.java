class Solution {
  public int cherryPickup(int[][] grid) {
    this.m = grid.length;
    this.n = grid[0].length;
    // dp[x][y1][y2] := max cherries we can collect w/
    // Robot #1 on (x, y1) and Robot #2 on (x, y2) first
    dp = new int[m][n][n];
    for (int[][] A : dp)
      Arrays.stream(A).forEach(a -> Arrays.fill(a, -1));
    return cherryPick(grid, 0, 0, n - 1);
  }

  private int m;
  private int n;
  private int[][][] dp;

  private int cherryPick(int[][] grid, int x, int y1, int y2) {
    if (x == m)
      return 0;
    if (y1 < 0 || y1 == n || y2 < 0 || y2 == n)
      return 0;
    if (dp[x][y1][y2] != -1)
      return dp[x][y1][y2];

    final int currRow = grid[x][y1] + (y1 == y2 ? 0 : 1) * grid[x][y2];

    for (int d1 = -1; d1 <= 1; ++d1)
      for (int d2 = -1; d2 <= 1; ++d2)
        dp[x][y1][y2] =
            Math.max(dp[x][y1][y2], currRow + cherryPick(grid, x + 1, y1 + d1, y2 + d2));

    return dp[x][y1][y2];
  }
}
