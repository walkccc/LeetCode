class Solution {
  public int maxProductPath(int[][] grid) {
    final int kMod = 1_000_000_007;
    final int m = grid.length;
    final int n = grid[0].length;
    // dpMin[i][j] := the minimum product from (0, 0) to (i, j)
    // dpMax[i][j] := the maximum product from (0, 0) to (i, j)
    long[][] dpMin = new long[m][n];
    long[][] dpMax = new long[m][n];

    dpMin[0][0] = dpMax[0][0] = grid[0][0];

    for (int i = 1; i < m; ++i)
      dpMin[i][0] = dpMax[i][0] = dpMin[i - 1][0] * grid[i][0];

    for (int j = 1; j < n; ++j)
      dpMin[0][j] = dpMax[0][j] = dpMin[0][j - 1] * grid[0][j];

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (grid[i][j] < 0) {
          dpMin[i][j] = Math.max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
          dpMax[i][j] = Math.min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
        } else {
          dpMin[i][j] = Math.min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
          dpMax[i][j] = Math.max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
        }

    final long mx = Math.max(dpMin[m - 1][n - 1], dpMax[m - 1][n - 1]);
    return mx < 0 ? -1 : (int) (mx % kMod);
  }
}
