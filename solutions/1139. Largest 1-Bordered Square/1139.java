class Solution {
  public int largest1BorderedSquare(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;

    // leftOnes[i][j] := consecutive 1s in the left of grid[i][j]
    int[][] leftOnes = new int[m][n];
    // topOnes[i][j] := consecutive 1s in the top of grid[i][j]
    int[][] topOnes = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          leftOnes[i][j] = j == 0 ? 1 : 1 + leftOnes[i][j - 1];
          topOnes[i][j] = i == 0 ? 1 : 1 + topOnes[i - 1][j];
        }

    for (int sz = Math.min(m, n); sz > 0; --sz)
      for (int i = 0; i + sz - 1 < m; ++i)
        for (int j = 0; j + sz - 1 < n; ++j) {
          final int x = i + sz - 1;
          final int y = j + sz - 1;
          // If grid[i..x][j..y] has all 1s on its border.
          if (Math.min(leftOnes[i][y], leftOnes[x][y]) >= sz &&
              Math.min(topOnes[x][j], topOnes[x][y]) >= sz)
            return sz * sz;
        }

    return 0;
  }
};
