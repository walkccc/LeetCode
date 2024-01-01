class Solution {
  public int getMaximumGold(int[][] grid) {
    int ans = 0;

    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        ans = Math.max(ans, dfs(grid, i, j));

    return ans;
  }

  private int dfs(int[][] grid, int i, int j) {
    if (i < 0 || j < 0 || i == grid.length || j == grid[0].length)
      return 0;
    if (grid[i][j] == 0)
      return 0;

    final int gold = grid[i][j];
    grid[i][j] = 0; // Mark as visited.
    final int maxPath = Math.max(Math.max(dfs(grid, i + 1, j), dfs(grid, i - 1, j)),
                                 Math.max(dfs(grid, i, j + 1), dfs(grid, i, j - 1)));
    grid[i][j] = gold;
    return gold + maxPath;
  }
}
