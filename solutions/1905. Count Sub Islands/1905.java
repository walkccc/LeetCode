class Solution {
  public int countSubIslands(int[][] grid1, int[][] grid2) {
    int ans = 0;

    for (int i = 0; i < grid2.length; ++i)
      for (int j = 0; j < grid2[0].length; ++j)
        if (grid2[i][j] == 1)
          ans += dfs(grid1, grid2, i, j);

    return ans;
  }

  private int dfs(int[][] grid1, int[][] grid2, int i, int j) {
    if (i < 0 || i == grid1.length || j < 0 || j == grid2[0].length)
      return 1;
    if (grid2[i][j] != 1)
      return 1;

    grid2[i][j] = 2; // mark 2 as visited

    return dfs(grid1, grid2, i + 1, j) & dfs(grid1, grid2, i - 1, j) &
           dfs(grid1, grid2, i, j + 1) & dfs(grid1, grid2, i, j - 1) & grid1[i][j];
  }
}
