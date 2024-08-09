class Solution {
  public int minimumOperationsToWriteY(int[][] grid) {
    return Math.min(Math.min(Math.min(getOperations(grid, 0, 1), getOperations(grid, 0, 2)),
                             Math.min(getOperations(grid, 1, 0), getOperations(grid, 1, 2))),
                    Math.min(getOperations(grid, 2, 0), getOperations(grid, 2, 1)));
  }

  // Returns the number of operations to turn Y into a and non-Y into b.
  private int getOperations(int[][] grid, int a, int b) {
    final int n = grid.length;
    final int mid = n / 2;
    int operations = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        // For the 'Y' pattern, before the midpoint, check the diagonal and
        // anti-diagonal. After the midpoint, check the middle column.
        if ((i < mid && (i == j || i + j == n - 1)) || (i >= mid && j == mid)) {
          if (grid[i][j] != a)
            ++operations;
        } else if (grid[i][j] != b) {
          ++operations;
        }
    return operations;
  }
}
