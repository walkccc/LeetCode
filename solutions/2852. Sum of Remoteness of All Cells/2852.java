class Solution {
  public long sumRemoteness(int[][] grid) {
    long ans = 0;
    long sum = 0;

    for (int[] row : grid)
      for (int cell : row)
        sum += Math.max(0, cell);

    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] > 0) {
          long[] res = dfs(grid, i, j);
          final long count = res[0];
          final long componentSum = res[1];
          ans += (sum - componentSum) * count;
        }

    return ans;
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};

  // Returns the (count, componentSum) of the connected component that contains
  // (x, y).
  private long[] dfs(int[][] grid, int i, int j) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return new long[] {0, 0};
    if (grid[i][j] == -1)
      return new long[] {0, 0};

    long count = 1;
    long componentSum = grid[i][j];
    grid[i][j] = -1; // Mark as visited.;

    for (int k = 0; k < 4; ++k) {
      final int x = i + dirs[k];
      final int y = j + dirs[k + 1];
      long[] nextRes = dfs(grid, x, y);
      final long nextCount = nextRes[0];
      final long nextComponentSum = nextRes[1];
      count += nextCount;
      componentSum += nextComponentSum;
    }

    return new long[] {count, componentSum};
  }
}
