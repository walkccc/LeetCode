class Solution {
  public int shortestPathBinaryMatrix(int[][] grid) {
    final int n = grid.length;
    if (grid[0][0] == 0 && n == 1)
      return 1;
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;

    final int[][] dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int ans = 0;
    Queue<int[]> q = new ArrayDeque<>();
    q.offer(new int[] {0, 0});
    boolean[][] seen = new boolean[n][n];
    seen[0][0] = true;

    while (!q.isEmpty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek()[0];
        final int j = q.poll()[1];
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (grid[x][y] != 0 || seen[x][y])
            continue;
          if (x == n - 1 && y == n - 1)
            return ans + 1;
          q.offer(new int[] {x, y});
          seen[x][y] = true;
        }
      }
    }

    return -1;
  }
}
