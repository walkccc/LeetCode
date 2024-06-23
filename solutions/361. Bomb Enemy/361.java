class Solution {
  public int maxKilledEnemies(char[][] grid) {
    if (grid.length == 0 || grid[0].length == 0)
      return 0;

    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i][j] := the maximum enemies grid[i][j] can kill
    int[][] dp = new int[m][n];

    // Extend the four directions, if meet 'W', need to start over from 0.
    for (int i = 0; i < m; ++i) {
      enemyCount = 0;
      for (int j = 0; j < n; ++j)
        update(grid, i, j, dp);
      enemyCount = 0;
      for (int j = n - 1; j >= 0; --j)
        update(grid, i, j, dp);
    }

    for (int j = 0; j < n; ++j) {
      enemyCount = 0;
      for (int i = 0; i < m; ++i)
        update(grid, i, j, dp);
      enemyCount = 0;
      for (int i = m - 1; i >= 0; --i)
        update(grid, i, j, dp);
    }

    return Arrays.stream(dp).flatMapToInt(Arrays::stream).max().getAsInt();
  }

  private int enemyCount = 0;

  private void update(char[][] grid, int i, int j, int[][] dp) {
    if (grid[i][j] == '0')
      dp[i][j] += enemyCount;
    else if (grid[i][j] == 'E')
      ++enemyCount;
    else // grid[i][j] == 'W'
      enemyCount = 0;
  }
}
