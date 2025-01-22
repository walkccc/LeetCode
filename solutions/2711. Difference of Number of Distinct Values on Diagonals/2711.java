class Solution {
  public int[][] differenceOfDistinctValues(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int[][] ans = new int[m][n];

    for (int i = 0; i < m; ++i)
      fillInDiagonal(grid, i, 0, ans);

    for (int j = 1; j < n; ++j)
      fillInDiagonal(grid, 0, j, ans);

    return ans;
  }

  private void fillInDiagonal(int[][] grid, int i, int j, int[][] ans) {
    Set<Integer> topLeft = new HashSet<>();
    Set<Integer> bottomRight = new HashSet<>();

    // Fill in the diagonal from the top-left to the bottom-right.
    while (i < grid.length && j < grid[0].length) {
      ans[i][j] = topLeft.size();
      // Post-addition, so this information can be utilized in subsequent cells.
      topLeft.add(grid[i++][j++]);
    }

    --i;
    --j;

    // Fill in the diagonal from the bottom-right to the top-left.
    while (i >= 0 && j >= 0) {
      ans[i][j] = Math.abs(ans[i][j] - bottomRight.size());
      // Post-addition, so this information can be utilized in subsequent cells.
      bottomRight.add(grid[i--][j--]);
    }
  }
}
