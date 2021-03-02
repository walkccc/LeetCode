class Solution {
  public int orderOfLargestPlusSign(int N, int[][] mines) {
    int[][] grid = new int[N][N];
    Arrays.stream(grid).forEach(row -> Arrays.fill(row, N));

    for (int[] mine : mines)
      grid[mine[0]][mine[1]] = 0;

    // extend four directions, if meet 0, need to start over from 0
    for (int i = 0; i < N; ++i) {
      for (int j = 0, leftToRight = 0; j < N; ++j) {
        leftToRight = (grid[i][j] == 0 ? 0 : leftToRight + 1);
        grid[i][j] = Math.min(grid[i][j], leftToRight);
      }
      for (int j = N - 1, rightToLeft = 0; j >= 0; --j) {
        rightToLeft = (grid[i][j] == 0 ? 0 : rightToLeft + 1);
        grid[i][j] = Math.min(grid[i][j], rightToLeft);
      }
      for (int j = 0, upToDown = 0; j < N; ++j) {
        upToDown = (grid[j][i] == 0 ? 0 : upToDown + 1);
        grid[j][i] = Math.min(grid[j][i], upToDown);
      }
      for (int j = N - 1, downToUp = 0; j >= 0; --j) {
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
