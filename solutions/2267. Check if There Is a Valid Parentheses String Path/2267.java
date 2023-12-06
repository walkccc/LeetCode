class Solution {
  public boolean hasValidPath(char[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i][j][k] := 1 if there's a path from grid[i][j] to grid[m - 1][n - 1],
    // where the number of '(' - the number of ')' == k
    dp = new Integer[m][n][m + n];
    return hasValidPath(grid, 0, 0, 0) == 1 ? true : false;
  }

  private Integer[][][] dp;

  private int hasValidPath(char[][] grid, int i, int j, int k) {
    if (i == grid.length || j == grid[0].length)
      return 0;
    k += grid[i][j] == '(' ? 1 : -1;
    if (k < 0)
      return 0;
    if (i == grid.length - 1 && j == grid[0].length - 1)
      return k == 0 ? 1 : 0;
    if (dp[i][j][k] != null)
      return dp[i][j][k];
    return dp[i][j][k] = hasValidPath(grid, i + 1, j, k) | hasValidPath(grid, i, j + 1, k);
  }
}
