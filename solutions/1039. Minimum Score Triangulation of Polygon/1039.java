class Solution {
  public int minScoreTriangulation(int[] values) {
    final int n = values.length;
    int[][] dp = new int[n][n];

    for (int j = 2; j < n; ++j)
      for (int i = j - 2; i >= 0; --i) {
        dp[i][j] = Integer.MAX_VALUE;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = Math.min(dp[i][j], dp[i][k] + values[i] * values[k] * values[j] + dp[k][j]);
      }

    return dp[0][n - 1];
  }
}
