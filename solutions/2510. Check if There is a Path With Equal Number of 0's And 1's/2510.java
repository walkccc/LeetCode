class Solution {
  public boolean isThereAPath(int[][] grid) {
    m = grid.length;
    n = grid[0].length;
    // Map negative (the number of 0s - the number of 1s) to non-negative one.
    cells = m + n - 1;
    if (cells % 2 == 1)
      return false;
    // dp[i][j][cells + k] := 1 if there's a path to grid[i][j] s.t.
    // k = (the number of 0s - the number of 1s).
    dp = new Boolean[m][n][cells * 2 + 1];
    return isThereAPath(grid, 0, 0, 0);
  }

  private int m;
  private int n;
  private int cells;
  private Boolean[][][] dp;

  private boolean isThereAPath(int[][] grid, int i, int j, int sum) {
    if (i == m || j == n)
      return false;
    sum += grid[i][j] == 0 ? 1 : -1;
    if (i == m - 1 && j == n - 1)
      return sum == 0;
    if (dp[i][j][cells + sum] != null)
      return dp[i][j][cells + sum];
    return dp[i][j][cells + sum] =
               isThereAPath(grid, i + 1, j, sum) || isThereAPath(grid, i, j + 1, sum);
  }
}
