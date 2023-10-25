class Solution {
  public int minDays(int[][] grid) {
    if (disconnected(grid))
      return 0;

    // Try to remove 1 land.
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          if (disconnected(grid))
            return 1;
          grid[i][j] = 1;
        }

    // Remove 2 lands.
    return 2;
  }

  private final int[] dirs = {0, 1, 0, -1, 0};

  private boolean disconnected(int[][] grid) {
    int islandsCount = 0;
    boolean[][] seen = new boolean[grid.length][grid[0].length];
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j) {
        if (grid[i][j] == 0 || seen[i][j])
          continue;
        if (++islandsCount > 1)
          return true;
        dfs(grid, i, j, seen);
      }

    return islandsCount != 1;
  }

  private void dfs(int[][] grid, int i, int j, boolean[][] seen) {
    seen[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      int x = i + dirs[k];
      int y = j + dirs[k + 1];
      if (x < 0 || x == grid.length || y < 0 || y == grid[0].length)
        continue;
      if (grid[x][y] == 0 || seen[x][y])
        continue;
      dfs(grid, x, y, seen);
    }
  }
}
