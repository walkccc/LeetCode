class Solution {
  public List<Integer> luckyNumbers(int[][] matrix) {
    for (int[] row : matrix) {
      final int minIndex = getMinIndex(row);
      if (row[minIndex] == maxNumOfColumn(matrix, minIndex))
        return List.of(row[minIndex]);
    }
    return new ArrayList<>();
  }

  private int getMinIndex(int[] row) {
    int minIndex = 0;
    for (int j = 0; j < row.length; ++j)
      if (row[j] < row[minIndex])
        minIndex = j;
    return minIndex;
  }

  private int maxNumOfColumn(int[][] matrix, int j) {
    int res = 0;
    for (int i = 0; i < matrix.length; ++i)
      res = Math.max(res, matrix[i][j]);
    return res;
  }
}
