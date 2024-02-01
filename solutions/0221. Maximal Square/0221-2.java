class Solution {
  public int maximalSquare(char[][] matrix) {
    final int m = matrix.length;
    final int n = matrix[0].length;
    int[] dp = new int[n];
    int maxLength = 0;
    int prev = 0; // dp[i - 1][j - 1]

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        final int cache = dp[j];
        if (i == 0 || j == 0 || matrix[i][j] == '0')
          dp[j] = matrix[i][j] == '1' ? 1 : 0;
        else
          dp[j] = Math.min(prev, Math.min(dp[j], dp[j - 1])) + 1;
        maxLength = Math.max(maxLength, dp[j]);
        prev = cache;
      }

    return maxLength * maxLength;
  }
}
