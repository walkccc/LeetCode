class Solution {
  public int shortestDistance(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    final int buildingCount = getBuildingCount(grid);

    int ans = Integer.MAX_VALUE;
    // dist[i][j] := total distance of grid[i][j] (0) to reach all buildings (1)
    int[][] dist = new int[m][n];
    // reachCount[i][j] := # of building grid[i][j] (0) can reach
    int[][] reachCount = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) // bfs from this building
          bfs(grid, i, j, dist, reachCount);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (reachCount[i][j] == buildingCount)
          ans = Math.min(ans, dist[i][j]);

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};

  private void bfs(int[][] grid, int row, int col, int[][] dist, int[][] reachCount) {
    final int m = grid.length;
    final int n = grid[0].length;

    Queue<int[]> q = new LinkedList<>();
    boolean[][] seen = new boolean[m][n];
    int depth = 0;

    q.offer(new int[] {row, col});

    while (!q.isEmpty()) {
      ++depth;
      for (int size = q.size(); size > 0; --size) {
        final int i = q.peek()[0];
        final int j = q.poll()[1];
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] != 0 || seen[x][y])
            continue;
          dist[x][y] += depth;
          ++reachCount[x][y];
          q.offer(new int[] {x, y});
          seen[x][y] = true;
        }
      }
    }
  }

  private int getBuildingCount(int[][] grid) {
    int buildingCount = 0;
    for (int[] row : grid)
      for (final int cell : row)
        if (cell == 1)
          ++buildingCount;
    return buildingCount;
  }
}
