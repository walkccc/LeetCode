class Solution {
  public boolean satisfiesConditions(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;

    for (int i = 0; i + 1 < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] != grid[i + 1][j])
          return false;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j + 1 < n; ++j)
        if (grid[i][j] == grid[i][j + 1])
          return false;

    return true;
  }
};
