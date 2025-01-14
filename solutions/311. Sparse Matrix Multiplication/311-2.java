class Solution {
  public int[][] multiply(int[][] mat1, int[][] mat2) {
    final int m = mat1.length;
    final int n = mat2.length;
    final int l = mat2[0].length;
    int[][] ans = new int[m][l];
    List<Integer>[] nonZeroColIndicesInMat2 = new List[n];

    for (int i = 0; i < n; ++i) {
      List<Integer> colIndices = new ArrayList<>();
      for (int j = 0; j < l; ++j)
        if (mat2[i][j] != 0)
          colIndices.add(j);
      nonZeroColIndicesInMat2[i] = colIndices;
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (mat1[i][j] == 0)
          continue;
        // mat1s j-th column matches mat2's j-th row
        for (final int colIndex : nonZeroColIndicesInMat2[j])
          ans[i][colIndex] += mat1[i][j] * mat2[j][colIndex];
      }

    return ans;
  }
}
