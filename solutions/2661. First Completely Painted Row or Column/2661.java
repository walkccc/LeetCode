class Solution {
  public int firstCompleteIndex(int[] arr, int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    // rows[i] := the number of painted grid in the i-th row
    int[] rows = new int[m];
    // cols[j] := the number of painted grid in the j-th column
    int[] cols = new int[n];
    // numToRow[num] := the i-th row of the `num` in the `mat`
    int[] numToRow = new int[m * n + 1];
    // numToCol[num] := the j-th column of the `num` in the `mat`
    int[] numToCol = new int[m * n + 1];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        numToRow[mat[i][j]] = i;
        numToCol[mat[i][j]] = j;
      }

    for (int i = 0; i < arr.length; ++i) {
      if (++rows[numToRow[arr[i]]] == n)
        return i;
      if (++cols[numToCol[arr[i]]] == m)
        return i;
    }

    throw new IllegalArgumentException();
  }
}
