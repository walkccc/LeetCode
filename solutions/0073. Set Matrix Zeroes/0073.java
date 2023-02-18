class Solution {
  public void setZeroes(int[][] matrix) {
    final int m = matrix.length;
    final int n = matrix[0].length;
    boolean shouldFillFirstRow = false;
    boolean shouldFillFirstCol = false;

    for (int j = 0; j < n; ++j)
      if (matrix[0][j] == 0) {
        shouldFillFirstRow = true;
        break;
      }

    for (int i = 0; i < m; ++i)
      if (matrix[i][0] == 0) {
        shouldFillFirstCol = true;
        break;
      }

    // Store the information in the 1st row/col
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }

    // Fill 0s for the matrix except the 1st row/col
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;

    // Fill 0s for the 1st row if needed
    if (shouldFillFirstRow)
      for (int j = 0; j < n; ++j)
        matrix[0][j] = 0;

    // Fill 0s for the 1st col if needed
    if (shouldFillFirstCol)
      for (int i = 0; i < m; ++i)
        matrix[i][0] = 0;
  }
}
