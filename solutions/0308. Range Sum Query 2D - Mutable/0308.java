class FenwickTree {
  public FenwickTree(int m, int n) {
    sums = new int[m + 1][n + 1];
  }

  public void update(int row, int col, int delta) {
    for (int i = row; i < sums.length; i += i & -i)
      for (int j = col; j < sums[0].length; j += j & -j)
        sums[i][j] += delta;
  }

  public int get(int row, int col) {
    int sum = 0;
    for (int i = row; i > 0; i -= i & -i)
      for (int j = col; j > 0; j -= j & -j)
        sum += sums[i][j];
    return sum;
  }

  private int[][] sums;
}

class NumMatrix {
  public NumMatrix(int[][] matrix) {
    this.matrix = matrix;
    tree = new FenwickTree(matrix.length, matrix[0].length);
    for (int i = 0; i < matrix.length; ++i)
      for (int j = 0; j < matrix[0].length; ++j)
        tree.update(i + 1, j + 1, matrix[i][j]);
  }

  public void update(int row, int col, int val) {
    tree.update(row + 1, col + 1, val - matrix[row][col]);
    matrix[row][col] = val;
  }

  public int sumRegion(int row1, int col1, int row2, int col2) {
    return tree.get(row2 + 1, col2 + 1) - tree.get(row1, col2 + 1) - tree.get(row2 + 1, col1) +
        tree.get(row1, col1);
  }

  private int[][] matrix;
  private FenwickTree tree;
}
