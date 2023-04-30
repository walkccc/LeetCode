class Solution {
  public void wallsAndGates(int[][] rooms) {
    final int m = rooms.length;
    final int n = rooms[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};
    Queue<int[]> q = new ArrayDeque<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (rooms[i][j] == 0)
          q.offer(new int[] {i, j});

    while (!q.isEmpty()) {
      int[] p = q.poll();
      final int i = p[0];
      final int j = p[1];
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
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
