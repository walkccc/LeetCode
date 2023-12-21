class Solution {
  public int numberOfPaths(int[][] grid, int k) {
    final int kMod = 1_000_000_007;
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i][j][sum] : = the number of paths to(i, j), where the sum / k == sum
    int[][][] dp = new int[m][n][k];
    dp[0][0][grid[0][0] % k] = 1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int sum = 0; sum < k; ++sum) {
          final int newSum = (sum + grid[i][j]) % k;
          if (i > 0)
            dp[i][j][newSum] += dp[i - 1][j][sum];
          if (j > 0)
            dp[i][j][newSum] += dp[i][j - 1][sum];
          dp[i][j][newSum] %= kMod;
        }

    return dp[m - 1][n - 1][0];
  }
}
