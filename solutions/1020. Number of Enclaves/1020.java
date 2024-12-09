class Solution {
  public int numEnclaves(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;

    // Remove the lands connected to the edge.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (grid[i][j] == 1)
            dfs(grid, i, j);

    return Arrays.stream(grid).flatMapToInt(Arrays::stream).sum();
  }

  private void dfs(int[][] grid, int i, int j) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return;
    if (grid[i][j] == 0)
      return;
    grid[i][j] = 0;
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
}
