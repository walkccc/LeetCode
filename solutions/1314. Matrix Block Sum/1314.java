class Solution {
  public int[][] matrixBlockSum(int[][] mat, int k) {
    final int m = mat.length;
    final int n = mat[0].length;
    int[][] ans = new int[m][n];
    int[][] prefix = new int[m + 1][n + 1];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        final int r1 = Math.max(0, i - k) + 1;
        final int c1 = Math.max(0, j - k) + 1;
        final int r2 = Math.min(m - 1, i + k) + 1;
        final int c2 = Math.min(n - 1, j + k) + 1;
        ans[i][j] =
            prefix[r2][c2] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2] + prefix[r1 - 1][c1 - 1];
      }

    return ans;
  }
}
