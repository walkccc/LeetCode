class Solution {
  public int maxSideLength(int[][] mat, int threshold) {
    final int m = mat.length;
    final int n = mat[0].length;
    int ans = 0;
    int[][] prefix = new int[m + 1][n + 1];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int length = ans; length < Math.min(m - i, n - j); ++length) {
          if (squareSum(prefix, i, j, i + length, j + length) > threshold)
            break;
          ans = Math.max(ans, length + 1);
        }

    return ans;
  }

  private int squareSum(int[][] prefix, int r1, int c1, int r2, int c2) {
    return prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - prefix[r2 + 1][c1] + prefix[r1][c1];
  }
}
