class Solution {
  public int findMaxFish(int[][] grid) {
    int ans = 0;

    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] > 0)
          ans = Math.max(ans, dfs(grid, i, j));

    return ans;
  }

  private int dfs(int[][] grid, int i, int j) {
    if (i < 0 || i == grid.length || j < 0 || j == grid.length)
      return 0;
    if (grid[i][j] == 0)
      return 0;
    int caughtFish = grid[i][j];
    grid[i][j] = 0;                                 // Mark 0 as visited
    return caughtFish +                             //
        dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + //
        dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
  }
}
