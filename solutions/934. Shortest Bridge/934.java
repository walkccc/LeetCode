class Solution {
  public int shortestBridge(int[][] grid) {
    markGridTwo(grid);

    for (int color = 2;; ++color)
      for (int i = 0; i < grid.length; ++i)
        for (int j = 0; j < grid[0].length; ++j)
          if (grid[i][j] == color)
            if (expand(grid, i + 1, j, color) || expand(grid, i - 1, j, color) ||
                expand(grid, i, j + 1, color) || expand(grid, i, j - 1, color))
              return color - 2;
  }

  // Marks one group to 2s by DFS.
  private void markGridTwo(int[][] grid) {
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] == 1) {
          markGridTwo(grid, i, j);
          return;
        }
  }

  private void markGridTwo(int[][] grid, int i, int j) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return;
    if (grid[i][j] != 1)
      return;
    grid[i][j] = 2;
    markGridTwo(grid, i + 1, j);
    markGridTwo(grid, i - 1, j);
    markGridTwo(grid, i, j + 1);
    markGridTwo(grid, i, j - 1);
  }

  // Returns true if we touch 1s' group through expanding.
  private boolean expand(int[][] grid, int i, int j, int color) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return false;
    if (grid[i][j] == 0)
      grid[i][j] = color + 1;
    return grid[i][j] == 1;
  }
}
