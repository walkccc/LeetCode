class Solution {
  public int lenOfVDiagonal(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    Integer[][][][][] mem = new Integer[m][n][2][2][4];

    int ans = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          for (int d = 0; d < 4; ++d) {
            final int dx = DIRS[d][0];
            final int dy = DIRS[d][1];
            ans = Math.max(ans, 1 + dfs(grid, i + dx, j + dy, /*turned=*/false, 2, d, mem));
          }

    return ans;
  }

  private static final int[][] DIRS = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

  private int dfs(int[][] grid, int i, int j, boolean turned, int num, int dir,
                  Integer[][][][][] mem) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return 0;
    if (grid[i][j] != num)
      return 0;

    final int hashNum = Math.max(0, num - 1);
    if (mem[i][j][turned ? 1 : 0][hashNum][dir] != null)
      return mem[i][j][turned ? 1 : 0][hashNum][dir];

    final int nextNum = num == 2 ? 0 : 2;
    final int dx = DIRS[dir][0], dy = DIRS[dir][1];
    int res = 1 + dfs(grid, i + dx, j + dy, turned, nextNum, dir, mem);

    if (!turned) {
      final int nextDir = (dir + 1) % 4;
      final int nextDx = DIRS[nextDir][0], nextDy = DIRS[nextDir][1];
      res = Math.max(res,
                     1 + dfs(grid, i + nextDx, j + nextDy, /*turned=*/true, nextNum, nextDir, mem));
    }

    return mem[i][j][turned ? 1 : 0][hashNum][dir] = res;
  }
}
