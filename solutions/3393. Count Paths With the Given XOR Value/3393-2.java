class Solution {
  public int countPathsWithXorValue(int[][] grid, int k) {
    final int kMod = 1_000_000_007;
    final int kMax = 15;
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i][j][xors] := the number of paths from (i, j) to (m - 1, n - 1) with
    // XOR value `xors`
    int[][][] dp = new int[m][n][kMax + 1];

    dp[m - 1][n - 1][grid[m - 1][n - 1]] = 1;

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j)
        for (int xors = 0; xors <= kMax; ++xors) {
          if (i - 1 >= 0) {
            final int newXor = xors ^ grid[i - 1][j];
            dp[i - 1][j][newXor] += dp[i][j][xors];
            dp[i - 1][j][newXor] %= kMod;
          }
          if (j - 1 >= 0) {
            final int newXor = xors ^ grid[i][j - 1];
            dp[i][j - 1][newXor] += dp[i][j][xors];
            dp[i][j - 1][newXor] %= kMod;
          }
        }

    return dp[0][0][k];
  }
}
