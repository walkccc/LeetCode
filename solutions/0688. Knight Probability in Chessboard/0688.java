class Solution {
  public double knightProbability(int n, int K, int r, int c) {
    final double kProb = 0.125;
    final int[][] dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    // dp[i][j] := probability to stand on (i, j)
    double[][] dp = new double[n][n];
    dp[r][c] = 1.0;

    for (int k = 0; k < K; ++k) {
      double[][] newDp = new double[n][n];
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (dp[i][j] > 0.0) {
            for (int[] dir : dirs) {
              final int x = i + dir[0];
              final int y = j + dir[1];
              if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
              newDp[x][y] += dp[i][j] * kProb;
            }
          }
      dp = newDp;
    }

    double ans = 0.0;
    for (double[] row : dp)
      ans += Arrays.stream(row).sum();
    return ans;
  }
}
