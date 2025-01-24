class Solution {
  public boolean containsCycle(char[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    boolean[][] seen = new boolean[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (seen[i][j])
          continue;
        if (dfs(grid, i, j, -1, -1, grid[i][j], seen))
          return true;
      }

    return false;
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private boolean dfs(char[][] grid, int i, int j, int prevI, int prevJ, char c, boolean[][] seen) {
    seen[i][j] = true;

    for (int[] dir : dirs) {
      final int x = i + dir[0];
      final int y = j + dir[1];
      if (x < 0 || x == grid.length || y < 0 || y == grid[0].length)
        continue;
      if (x == prevI && y == prevJ)
        continue;
      if (grid[x][y] != c)
        continue;
      if (seen[x][y])
        return true;
      if (dfs(grid, x, y, i, j, c, seen))
        return true;
    }

    return false;
  }
}
