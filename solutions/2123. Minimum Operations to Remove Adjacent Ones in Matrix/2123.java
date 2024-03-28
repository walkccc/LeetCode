class Solution {
  public int minimumOperations(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    int[][] seen = new int[m][n];
    int[][] match = new int[m][n];
    Arrays.stream(match).forEach(A -> Arrays.fill(A, -1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1 && match[i][j] == -1) {
          final int sessionId = i * n + j;
          seen[i][j] = sessionId;
          if (dfs(grid, i, j, sessionId, seen, match))
            ++ans;
        }

    return ans;
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private boolean dfs(final int[][] grid, int i, int j, int sessionId, int[][] seen,
                      int[][] match) {
    final int m = grid.length;
    final int n = grid[0].length;

    for (int[] dir : dirs) {
      final int x = i + dir[0];
      final int y = j + dir[1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (grid[x][y] == 0 || seen[x][y] == sessionId)
        continue;
      seen[x][y] = sessionId;
      if (match[x][y] == -1 ||
          dfs(grid, match[x][y] / n, match[x][y] % n, sessionId, seen, match)) {
        match[x][y] = i * n + j;
        match[i][j] = x * n + y;
        return true;
      }
    }

    return false;
  }
}
