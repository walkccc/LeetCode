class Solution {
  public int longestLine(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    int ans = 0;
    // dp[i][j][0] := horizontal
    // dp[i][j][1] := vertical
    // dp[i][j][2] := diagonal
    // dp[i][j][3] := anti-diagonal
    int[][][] dp = new int[m][n][4];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 1) {
          dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
          dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;
          dp[i][j][2] = (i > 0 && j > 0) ? dp[i - 1][j - 1][2] + 1 : 1;
          dp[i][j][3] = (i > 0 && j < n - 1) ? dp[i - 1][j + 1][3] + 1 : 1;
          for (int k = 0; k < 4; ++k)
            ans = Math.max(ans, dp[i][j][k]);
        }

    return ans;
  }
}
