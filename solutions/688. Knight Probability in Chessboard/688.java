class Solution {
  public double knightProbability(int n, int k, int row, int column) {
    final int[][] dirs = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    final double kProb = 0.125;
    // dp[i][j] := the probability to stand on (i, j)
    double[][] dp = new double[n][n];
    dp[row][column] = 1.0;

    for (int move = 0; move < k; ++move) {
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

    return Arrays.stream(dp).flatMapToDouble(Arrays::stream).sum();
  }
}
