class Solution {
  public int orderOfLargestPlusSign(int n, int[][] mines) {
    int[][] grid = new int[n][n];
    Arrays.stream(grid).forEach(row -> Arrays.fill(row, n));

    for (int[] mine : mines)
      grid[mine[0]][mine[1]] = 0;

    // Extend the four directions. If meet 0, need to start over from 0.
    for (int i = 0; i < n; ++i) {
      for (int j = 0, leftToRight = 0; j < n; ++j) {
        leftToRight = (grid[i][j] == 0 ? 0 : leftToRight + 1);
        grid[i][j] = Math.min(grid[i][j], leftToRight);
      }
      for (int j = n - 1, rightToLeft = 0; j >= 0; --j) {
        rightToLeft = (grid[i][j] == 0 ? 0 : rightToLeft + 1);
        grid[i][j] = Math.min(grid[i][j], rightToLeft);
      }
      for (int j = 0, upToDown = 0; j < n; ++j) {
        upToDown = (grid[j][i] == 0 ? 0 : upToDown + 1);
        grid[j][i] = Math.min(grid[j][i], upToDown);
      }
      for (int j = n - 1, downToUp = 0; j >= 0; --j) {
        downToUp = (grid[j][i] == 0) ? 0 : downToUp + 1;
        grid[j][i] = Math.min(grid[j][i], downToUp);
      }
    }

    int ans = 0;

    for (int[] row : grid)
      ans = Math.max(ans, Arrays.stream(row).max().getAsInt());

    return ans;
  }
}
