class Solution {
  public int knightDialer(int n) {
    final int kMod = 1_000_000_007;
    final int[][] dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    // dp[i][j] := # of ways to stand on (i, j)
    int[][] dp = new int[4][3];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, 1));
    dp[3][0] = dp[3][2] = 0;

    for (int k = 0; k < n - 1; ++k) {
      int[][] newDp = new int[4][3];
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j) {
          if (isNotNumericCell(i, j))
            continue;
          for (int[] dir : dirs) {
            final int x = i + dir[0];
            final int y = j + dir[1];
            if (x < 0 || x >= 4 || y < 0 || y >= 3)
              continue;
            if (isNotNumericCell(x, y))
              continue;
            newDp[i][j] = (newDp[i][j] + dp[x][y]) % kMod;
          }
        }
      dp = newDp;
    }

    int ans = 0;

    for (int[] row : dp)
      for (final int a : row)
        ans = (ans + a) % kMod;

    return ans;
  }

  private boolean isNotNumericCell(int i, int j) {
    return i == 3 && (j == 0 || j == 2);
  }
}
