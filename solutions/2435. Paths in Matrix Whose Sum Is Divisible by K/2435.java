class Solution {
  public int numberOfPaths(int[][] grid, int k) {
    m = grid.length;
    n = grid[0].length;
    // dp[i][j][sum] := # of paths till (i, j) where the sum divide by k == sum
    dp = new Integer[m][n][k];
    return numberOfPaths(grid, 0, 0, 0, k);
  }

  private static final int kMod = 1_000_000_007;
  private int m;
  private int n;
  private Integer[][][] dp;

  private int numberOfPaths(int[][] grid, int i, int j, int sum, int k) {
    if (i == m || j == n)
      return 0;
    if (i == m - 1 && j == n - 1)
      return (sum + grid[i][j]) % k == 0 ? 1 : 0;
    if (dp[i][j][sum] != null)
      return dp[i][j][sum];
    final int newSum = (sum + grid[i][j]) % k;
    return dp[i][j][sum] = (numberOfPaths(grid, i + 1, j, newSum, k) +
                            numberOfPaths(grid, i, j + 1, newSum, k)) %
                           kMod;
  }
}
