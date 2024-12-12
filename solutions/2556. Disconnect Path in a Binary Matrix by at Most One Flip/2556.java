class Solution {
  public boolean isPossibleToCutPath(int[][] grid) {
    if (!hasPath(grid, 0, 0))
      return true;
    // Reassign (0, 0) as 1.
    grid[0][0] = 1;
    return !hasPath(grid, 0, 0);
  }

  // Returns true is there's a path from (0, 0) to (m - 1, n - 1).
  // Also marks the visited path as 0 except (m - 1, n - 1).
  private boolean hasPath(int[][] grid, int i, int j) {
    if (i == grid.length || j == grid[0].length)
      return false;
    if (i == grid.length - 1 && j == grid[0].length - 1)
      return true;
    if (grid[i][j] == 0)
      return false;

    grid[i][j] = 0;
    // Go down first. Since we use OR logic, we'll only mark one path.
    return hasPath(grid, i + 1, j) || hasPath(grid, i, j + 1);
  }
}
