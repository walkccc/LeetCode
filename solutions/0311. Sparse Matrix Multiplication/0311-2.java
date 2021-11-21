class Solution {
  public int[][] multiply(int[][] A, int[][] B) {
    final int m = A.length;
    final int n = B.length;
    final int l = B[0].length;

    int[][] ans = new int[m][l];
    List<Integer>[] nonZeroColIndicesInB = new List[n];

    for (int i = 0; i < n; ++i) {
      List<Integer> colIndices = new ArrayList<>();
      for (int j = 0; j < l; ++j)
        if (B[i][j] != 0)
          colIndices.add(j);
      nonZeroColIndicesInB[i] = colIndices;
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (A[i][j] == 0)
          continue;
        // A's j-th column matches B's j-th row
        for (final int colIndex : nonZeroColIndicesInB[j])
          ans[i][colIndex] += A[i][j] * B[j][colIndex];
      }

    return ans;
  }
}
