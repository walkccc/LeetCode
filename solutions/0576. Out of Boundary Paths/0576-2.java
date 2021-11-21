class Solution {
  public int findPaths(int m, int n, int N, int i, int j) {
    final int kMod = (int) 1e9 + 7;
    final int[] dirs = {0, 1, 0, -1, 0};

    int ans = 0;
    // dp[i][j] := # of paths to move the ball (i, j) out of bound
    int[][] dp = new int[m][n];
    dp[i][j] = 1;

    while (N-- > 0) {
      int[][] newDp = new int[m][n];
      for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
          if (dp[r][c] > 0)
            for (int k = 0; k < 4; ++k) {
              final int x = r + dirs[k];
              final int y = c + dirs[k + 1];
              if (x < 0 || x == m || y < 0 || y == n)
                ans = (ans + dp[r][c]) % kMod;
              else
                newDp[x][y] = (newDp[x][y] + dp[r][c]) % kMod;
            }
      dp = newDp;
    }

    return ans;
  }
}
