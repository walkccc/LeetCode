class Solution {
  public int[][] multiply(int[][] A, int[][] B) {
    final int l = A.length;
    final int m = B.length;
    final int n = B[0].length;

    int[][] ans = new int[l][n];
    List<Integer>[] nonZeroColIndicesInB = new List[m];

    for (int i = 0; i < m; ++i) {
      List<Integer> colIndices = new ArrayList<>();
      for (int j = 0; j < n; ++j)
        if (B[i][j] != 0)
          colIndices.add(j);
      nonZeroColIndicesInB[i] = colIndices;
    }

    for (int i = 0; i < l; ++i)
      for (int j = 0; j < m; ++j) {
        if (A[i][j] == 0)
          continue;
        for (final int colIndex : nonZeroColIndicesInB[j])
          ans[i][colIndex] += A[i][j] * B[j][colIndex];
      }

    return ans;
  }
}