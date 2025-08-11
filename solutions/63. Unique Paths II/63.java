class Solution {
  public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    final int m = obstacleGrid.length;
    final int n = obstacleGrid[0].length;
    // dp[i][j] := the number of unique paths from (0, 0) to (i, j)
    long[][] dp = new long[m + 1][n + 1];
    dp[0][1] = 1; // Can also set dp[1][0] = 1.

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (obstacleGrid[i - 1][j - 1] == 0)
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return (int) dp[m][n];
  }
}
