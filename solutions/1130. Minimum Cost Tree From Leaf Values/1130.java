class Solution {
  public int mctFromLeafValues(int[] arr) {
    final int n = arr.length;
    // dp[i][j] := min cost of arr[i..j]
    int[][] dp = new int[n][n];
    // maxVal[i][j] := max value of arr[i..j]
    int[][] maxVal = new int[n][n];

    for (int i = 0; i < n; ++i)
      maxVal[i][i] = arr[i];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        maxVal[i][j] = Math.max(maxVal[i][j - 1], maxVal[i + 1][j]);
      }

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        dp[i][j] = Integer.MAX_VALUE;
        for (int k = i; k < j; ++k)
          dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxVal[i][k] * maxVal[k + 1][j]);
      }

    return dp[0][n - 1];
  }
}
