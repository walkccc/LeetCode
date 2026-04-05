class Solution {
  public int shortestDistance(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    final int nBuildings = getBuildingsCount(grid);
    int ans = Integer.MAX_VALUE;
    // dist[i][j] := the total distance of grid[i][j] (0) to reach all the
    // buildings (1)
    int[][] dist = new int[m][n];
    // reachCount[i][j] := the number of buildings (1) grid[i][j] (0) can reach
    int[][] reachCount = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) // BFS from this building.
          if (!bfs(grid, i, j, dist, reachCount, nBuildings))
            return -1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (reachCount[i][j] == nBuildings)
          ans = Math.min(ans, dist[i][j]);

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }

  private static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private boolean bfs(int[][] grid, int row, int col, int[][] dist, int[][] reachCount,
                      int nBuildings) {
    final int m = grid.length;
    final int n = grid[0].length;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(row, col)));
    boolean[][] seen = new boolean[m][n];
    seen[row][col] = true;
    int seenBuildings = 1;

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int[] dir : DIRS) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y])
            continue;
          seen[x][y] = true;
          if (grid[x][y] == 0) {
            dist[x][y] += step;
            ++reachCount[x][y];
            q.offer(new Pair<>(x, y));
          } else if (grid[x][y] == 1) {
            ++seenBuildings;
          }
        }
      }

    return seenBuildings == nBuildings;
  }

  private int getBuildingsCount(int[][] grid) {
    int buildingCount = 0;
    for (int[] row : grid)
      for (final int cell : row)
        if (cell == 1)
          ++buildingCount;
    return buildingCount;
  }
}
