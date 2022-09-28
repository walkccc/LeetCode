class Solution {
  public int matrixScore(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = m; // all cells in the first col are 1

    for (int j = 1; j < n; ++j) {
      int onesCount = 0;
      for (int i = 0; i < m; ++i)
        // the best strategy is flip a row with leading 0
        onesCount += grid[i][j] == grid[i][0] ? 1 : 0;
      ans = ans * 2 + Math.max(onesCount, m - onesCount);
    }

    return ans;
  }
}
