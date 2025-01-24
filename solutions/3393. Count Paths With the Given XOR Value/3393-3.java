class Solution {
  public int countPathsWithXorValue(int[][] grid, int k) {
    final int kMod = 1_000_000_007;
    final int kMax = 15;
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i][j][xors] := the number of paths from (0, 0) to (i, j) with XOR
    // value `xors`
    int[][][] dp = new int[m][n][kMax + 1];

    dp[0][0][grid[0][0]] = 1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int xors = 0; xors <= kMax; ++xors) {
          if (i + 1 < m) {
            final int newXor = xors ^ grid[i + 1][j];
            dp[i + 1][j][newXor] += dp[i][j][xors];
            dp[i + 1][j][newXor] %= kMod;
          }
          if (j + 1 < n) {
            final int newXor = xors ^ grid[i][j + 1];
            dp[i][j + 1][newXor] += dp[i][j][xors];
            dp[i][j + 1][newXor] %= kMod;
          }
        }

    return dp[m - 1][n - 1][k];
  }
}
