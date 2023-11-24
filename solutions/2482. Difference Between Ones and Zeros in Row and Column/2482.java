class Solution {
  public int[][] onesMinusZeros(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int[][] ans = new int[m][n];
    int[] onesRow = new int[m];
    int[] onesCol = new int[n];

    for (int i = 0; i < m; ++i)
      onesRow[i] = (int) Arrays.stream(grid[i]).filter(a -> a == 1).count();

    for (int j = 0; j < n; ++j) {
      int ones = 0;
      for (int i = 0; i < m; ++i)
        ones += grid[i][j];
      onesCol[j] = ones;
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans[i][j] = onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);

    return ans;
  }
}
