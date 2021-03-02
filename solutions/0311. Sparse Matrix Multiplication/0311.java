class Solution {
  public int[][] multiply(int[][] A, int[][] B) {
    final int m = A.length;
    final int n = B.length;
    final int l = B[0].length;

    int[][] ans = new int[m][l];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < l; ++j)
        for (int k = 0; k < n; ++k)
          ans[i][j] += A[i][k] * B[k][j];

    return ans;
  }
}
