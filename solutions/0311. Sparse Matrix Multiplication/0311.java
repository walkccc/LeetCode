class Solution {
  public int[][] multiply(int[][] mat1, int[][] mat2) {
    final int m = mat1.length;
    final int n = mat2.length;
    final int l = mat2[0].length;
    int[][] ans = new int[m][l];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < l; ++j)
        for (int k = 0; k < n; ++k)
          ans[i][j] += mat1[i][k] * mat2[k][j];

    return ans;
  }
}
