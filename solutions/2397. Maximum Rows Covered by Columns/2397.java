class Solution {
  public int maximumRows(int[][] matrix, int numSelect) {
    dfs(matrix, /*colIndex=*/0, numSelect, /*mask=*/0);
    return ans;
  }

  private int ans = 0;

  private void dfs(int[][] matrix, int colIndex, int leftColsCount, int mask) {
    if (leftColsCount == 0) {
      ans = Math.max(ans, getAllZerosRowCount(matrix, mask));
      return;
    }
    if (colIndex == matrix[0].length)
      return;

    // choose this column
    dfs(matrix, colIndex + 1, leftColsCount - 1, mask | 1 << colIndex);
    // not choose this column
    dfs(matrix, colIndex + 1, leftColsCount, mask);
  }

  int getAllZerosRowCount(int[][] matrix, int mask) {
    int count = 0;
    for (int[] row : matrix) {
      boolean isAllZeros = true;
      for (int i = 0; i < row.length; ++i) {
        if (row[i] == 1 && (mask >> i & 1) == 0) {
          isAllZeros = false;
          break;
        }
      }
      if (isAllZeros)
        ++count;
    }
    return count;
  }
}
