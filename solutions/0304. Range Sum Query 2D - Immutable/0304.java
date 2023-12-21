class NumMatrix {
  public NumMatrix(int[][] matrix) {
    if (matrix.length == 0)
      return;

    final int m = matrix.length;
    final int n = matrix[0].length;
    // prefix[i][j] := the sum of matrix[0..i)[0..j)
    prefix = new int[m + 1][n + 1];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        prefix[i + 1][j + 1] = matrix[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
  }

  public int sumRegion(int row1, int col1, int row2, int col2) {
    return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] //
        - prefix[row2 + 1][col1] + prefix[row1][col1];
  }

  private int[][] prefix;
}
