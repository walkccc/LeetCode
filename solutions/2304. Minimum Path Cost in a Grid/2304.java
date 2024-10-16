class Solution {
  public int minPathCost(int[][] grid, int[][] moveCost) {
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i][j] := the minimum cost to reach grid[i][j]
    int[][] dp = new int[m][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    dp[0] = grid[0];

    for (int i = 1; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);

    return Arrays.stream(dp[m - 1]).min().getAsInt();
  }
}
