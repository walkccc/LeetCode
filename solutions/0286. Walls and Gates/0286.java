class Solution {
  public void wallsAndGates(int[][] rooms) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = rooms.length;
    final int n = rooms[0].length;
    Queue<int[]> q = new ArrayDeque<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (rooms[i][j] == 0)
          q.offer(new int[] {i, j});

    while (!q.isEmpty()) {
      int[] p = q.poll();
      final int i = p[0];
      final int j = p[1];
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (rooms[x][y] != Integer.MAX_VALUE)
          continue;
        rooms[x][y] = rooms[i][j] + 1;
        q.offer(new int[] {x, y});
      }
    }
  }
}
