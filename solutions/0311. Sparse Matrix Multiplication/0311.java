class Solution {
  public int[][] multiply(int[][] A, int[][] B) {
    final int l = A.length;
    final int m = B.length;
    final int n = B[0].length;

    int[][] ans = new int[l][n];

    for (int i = 0; i < l; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < m; ++k)
          ans[i][j] += A[i][k] * B[k][j];

    return ans;
  }
}