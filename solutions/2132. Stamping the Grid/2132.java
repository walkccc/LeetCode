class Solution {
  public boolean possibleToStamp(int[][] grid, int stampHeight, int stampWidth) {
    final int m = grid.length;
    final int n = grid[0].length;
    // A[i][j] := # of 1s in grid[0..i)[0..j)
    int[][] A = new int[m + 1][n + 1];
    // B[i][j] := # of ways to stamp the submatrix in [0..i)[0..j)
    int[][] B = new int[m + 1][n + 1];
    // fit[i][j] := 1 if the stamps can fit with right-bottom at (i, j)
    int[][] fit = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        A[i + 1][j + 1] = A[i + 1][j] + A[i][j + 1] - A[i][j] + grid[i][j];
        if (i + 1 >= stampHeight && j + 1 >= stampWidth) {
          final int x = i - stampHeight + 1;
          final int y = j - stampWidth + 1;
          if (A[i + 1][j + 1] - A[x][j + 1] - A[i + 1][y] + A[x][y] == 0)
            fit[i][j] = 1;
        }
      }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + fit[i][j];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0) {
          final int x = Math.min(i + stampHeight, m);
          final int y = Math.min(j + stampWidth, n);
          if (B[x][y] - B[i][y] - B[x][j] + B[i][j] == 0)
            return false;
        }

    return true;
  }
}
