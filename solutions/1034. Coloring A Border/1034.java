class Solution {
  public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
    dfs(grid, r0, c0, grid[r0][c0]);

    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] < 0)
          grid[i][j] = color;

    return grid;
  }

  private void dfs(int[][] grid, int i, int j, int originalColor) {
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] != originalColor)
      return;

    grid[i][j] = -originalColor;
    dfs(grid, i + 1, j, originalColor);
    dfs(grid, i - 1, j, originalColor);
    dfs(grid, i, j + 1, originalColor);
    dfs(grid, i, j - 1, originalColor);

    if (i > 0 && i + 1 < grid.length && j > 0 && j + 1 < grid[0].length && Math.abs(grid[i + 1][j]) == originalColor
        && Math.abs(grid[i - 1][j]) == originalColor && Math.abs(grid[i][j + 1]) == originalColor
        && Math.abs(grid[i][j - 1]) == originalColor)
      grid[i][j] = originalColor;
  }
}