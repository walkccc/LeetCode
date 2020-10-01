class Solution {
  public int maxSideLength(int[][] mat, int threshold) {
    final int m = mat.length;
    final int n = mat[0].length;

    int ans = 0;
    int[][] prefixSum = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int length = ans; length < Math.min(m - i, n - j); ++length) {
          if (squareSum(prefixSum, i, j, i + length, j + length) > threshold)
            break;
          ans = Math.max(ans, length + 1);
        }

    return ans;
  }

  private int squareSum(int[][] prefixSum, int r1, int c1, int r2, int c2) {
    return prefixSum[r2 + 1][c2 + 1] - prefixSum[r1][c2 + 1] - prefixSum[r2 + 1][c1] + prefixSum[r1][c1];
  }
}