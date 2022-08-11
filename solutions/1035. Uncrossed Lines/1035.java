class Solution {
  public int maxUncrossedLines(int[] A, int[] B) {
    final int m = A.length;
    final int n = B.length;
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] =
            A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : Math.max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
}
