class Solution {
  public boolean checkXMatrix(int[][] grid) {
    final int n = grid.length;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i == j || i + j == n - 1) { // In diagonal
          if (grid[i][j] == 0)
            return false;
        } else if (grid[i][j] > 0) { // Not in diagonal
          return false;
        }

    return true;
  }
}
