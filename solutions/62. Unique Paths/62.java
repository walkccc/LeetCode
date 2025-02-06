class Solution {
  public int uniquePaths(int m, int n) {
    // dp[i][j] := the number of unique paths from (0, 0) to (i, j)
    int[][] dp = new int[m][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, 1));

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
  }
}
