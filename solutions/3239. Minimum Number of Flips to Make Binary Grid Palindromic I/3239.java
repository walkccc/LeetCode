class Solution {
  public int minFlips(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int rowFlips = 0;
    int colFlips = 0;

    for (int[] row : grid)
      for (int i = 0; i < n / 2; ++i)
        if (row[i] != row[n - 1 - i])
          ++rowFlips;

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m / 2; ++i)
        if (grid[i][j] != grid[m - 1 - i][j])
          ++colFlips;

    return Math.min(rowFlips, colFlips);
  }
}
