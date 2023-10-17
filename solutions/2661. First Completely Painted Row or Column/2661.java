class Solution {
  public int firstCompleteIndex(int[] arr, int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    // rows[i] := # of painted grid in i-th row
    int[] rows = new int[m];
    // cols[j] := # of painted grid in j-th col
    int[] cols = new int[n];
    // numToRow[num] := i-th row of num in mat
    int[] numToRow = new int[m * n + 1];
    // numToCol[num] := j-th col of num in mat
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
