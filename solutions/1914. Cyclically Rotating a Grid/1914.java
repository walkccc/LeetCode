class Solution {
  public int[][] rotateGrid(int[][] grid, int k) {
    final int m = grid.length;
    final int n = grid[0].length;
    int t = 0;     // top
    int l = 0;     // left
    int b = m - 1; // bottom
    int r = n - 1; // right

    while (t < b && l < r) {
      final int elementInThisLayer = 2 * (b - t + 1) + 2 * (r - l + 1) - 4;
      final int netRotations = k % elementInThisLayer;
      for (int rotate = 0; rotate < netRotations; ++rotate) {
        final int topLeft = grid[t][l];
        for (int j = l; j < r; ++j)
          grid[t][j] = grid[t][j + 1];
        for (int i = t; i < b; ++i)
          grid[i][r] = grid[i + 1][r];
        for (int j = r; j > l; --j)
          grid[b][j] = grid[b][j - 1];
        for (int i = b; i > t; --i)
          grid[i][l] = grid[i - 1][l];
        grid[t + 1][l] = topLeft;
      }
      ++t;
      ++l;
      --b;
      --r;
    }

    return grid;
  }
}
