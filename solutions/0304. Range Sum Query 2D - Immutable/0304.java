class NumMatrix {
  public NumMatrix(int[][] matrix) {
    if (matrix.length == 0)
      return;

    final int m = matrix.length;
    final int n = matrix[0].length;

    prefixSum = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] +
                          prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
  }

  public int sumRegion(int row1, int col1, int row2, int col2) {
    return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1] -
           prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
  }

  private int[][] prefixSum;
}