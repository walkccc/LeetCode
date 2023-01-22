class Solution {
  public double knightProbability(int N, int K, int r, int c) {
    final double kProb = 0.125;
    final int[][] dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    // dp[i][j] := probability to stand on (i, j)
    double[][] dp = new double[N][N];
    dp[r][c] = 1.0;

    for (int k = 0; k < K; ++k) {
      double[][] newDp = new double[N][N];
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          if (dp[i][j] > 0.0) {
            for (int[] dir : dirs) {
              final int x = i + dir[0];
              final int y = j + dir[1];
              if (x < 0 || x >= N || y < 0 || y >= N)
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
