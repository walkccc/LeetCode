class Solution {
  public boolean isThereAPath(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // Map negative (the number of 0s - the number of 1s) to non-negative one.
    final int cells = m + n - 1;
    if (cells % 2 == 1)
      return false;
    Boolean[][][] mem = new Boolean[m][n][cells * 2 + 1];
    return isThereAPath(grid, 0, 0, 0, cells, mem);
  }

  // Returns 1 if there's a path to grid[i][j]
  // s.t. `sum` = (the number of 0s - the number of 1s).
  private boolean isThereAPath(int[][] grid, int i, int j, int sum, final int cells,
                               Boolean[][][] mem) {
    if (i == grid.length || j == grid[0].length)
      return false;
    sum += grid[i][j] == 0 ? 1 : -1;
    if (i == grid.length - 1 && j == grid[0].length - 1)
      return sum == 0;
    final int k = cells + sum;
    if (mem[i][j][k] != null)
      return mem[i][j][k];
    return mem[i][j][k] = isThereAPath(grid, i + 1, j, sum, cells, mem) ||
                          isThereAPath(grid, i, j + 1, sum, cells, mem);
  }
}
