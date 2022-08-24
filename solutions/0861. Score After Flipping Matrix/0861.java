class Solution {
  public int matrixScore(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;

    // flip rows with leading 0
    for (int[] row : grid)
      if (row[0] == 0)
        flip(row);

    // flip cols with 1s < 0s
    for (int j = 0; j < n; ++j)
      if (onesColCount(grid, j) * 2 < m)
        flipCol(grid, j);

    // add binary number for each row
    for (int[] row : grid)
      ans += binary(row);

    return ans;
  }

  private void flip(int[] row) {
    for (int i = 0; i < row.length; ++i)
      row[i] ^= 1;
  }

  private int onesColCount(int[][] grid, int j) {
    int ones = 0;
    for (int i = 0; i < grid.length; ++i)
      ones += grid[i][j];
    return ones;
  }

  private void flipCol(int[][] grid, int j) {
    for (int i = 0; i < grid.length; ++i)
      grid[i][j] ^= 1;
  }

  private int binary(int[] row) {
    int res = row[0];
    for (int j = 1; j < row.length; ++j)
      res = res * 2 + row[j];
    return res;
  }
}
