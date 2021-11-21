class T {
  public int i;
  public int j;
  public int r;
  public T(int i, int j, int r) {
    this.i = i;
    this.j = j;
    this.r = r; // remaining
  }
}

class Solution {
  public int shortestPath(int[][] grid, int k) {
    final int m = grid.length;
    final int n = grid[0].length;
    if (m == 1 && n == 1)
      return 0;

    final int[] dirs = {0, 1, 0, -1, 0};

    int steps = 0;
    Queue<T> q = new LinkedList<>();
    q.offer(new T(0, 0, k));
    boolean[][][] seen = new boolean[m][n][k + 1];
    seen[0][0][k] = true;

    while (!q.isEmpty()) {
      ++steps;
      for (int size = q.size(); size > 0; --size) {
        final int i = q.peek().i;
        final int j = q.peek().j;
        final int r = q.poll().r;
        for (int l = 0; l < 4; ++l) {
          final int x = i + dirs[l];
          final int y = j + dirs[l + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (x == m - 1 && y == n - 1)
            return steps;
          if (grid[x][y] == 1 && r == 0)
            continue;
          final int newR = r - grid[x][y];
          if (seen[x][y][newR])
            continue;
          q.offer(new T(x, y, newR));
          seen[x][y][newR] = true;
        }
      }
    }

    return -1;
  }
}
