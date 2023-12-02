class Solution {
  public int countPaths(int[][] grid) {
    m = grid.length;
    n = grid[0].length;
    int ans = 0;
    // dp[i][j] := the number of increasing paths starting from (i, j)
    dp = new int[m][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, -1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        ans += dfs(grid, i, j);
        ans %= kMod;
      }

    return ans;
  }

  private static final int kMod = 1_000_000_007;
  private final int[] dirs = {0, 1, 0, -1, 0};
  private int m;
  private int n;
  private int[][] dp;

  private int dfs(int[][] grid, int i, int j) {
    if (dp[i][j] != -1)
      return dp[i][j];

    dp[i][j] = 1; // The current cell contributes 1 length.

    for (int k = 0; k < 4; ++k) {
      final int x = i + dirs[k];
      final int y = j + dirs[k + 1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (grid[x][y] <= grid[i][j])
        continue;
      dp[i][j] += dfs(grid, x, y);
      dp[i][j] %= kMod;
    }

    return dp[i][j];
  }
}
