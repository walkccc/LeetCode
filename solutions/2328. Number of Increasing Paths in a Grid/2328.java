class Solution {
  public int countPaths(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    Integer[][] mem = new Integer[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        ans += countPaths(grid, i, j, mem);
        ans %= kMod;
      }

    return ans;
  }

  private static final int kMod = 1_000_000_007;
  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // Returns the number of increasing paths starting from (i, j).
  private int countPaths(int[][] grid, int i, int j, Integer[][] mem) {
    if (mem[i][j] != null)
      return mem[i][j];

    mem[i][j] = 1; // The current cell contributes 1 length.

    for (int[] dir : dirs) {
      int x = i + dir[0];
      int y = j + dir[1];
      if (x < 0 || x == grid.length || y < 0 || y == grid[0].length)
        continue;
      if (grid[x][y] <= grid[i][j])
        continue;
      mem[i][j] += countPaths(grid, x, y, mem);
      mem[i][j] %= kMod;
    }

    return mem[i][j];
  }
}
