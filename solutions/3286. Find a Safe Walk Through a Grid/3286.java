class Solution {
  public boolean findSafeWalk(List<List<Integer>> grid, int health) {
    record T(int i, int j, int h) {}
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = grid.size();
    final int n = grid.get(0).size();
    final int initialHealth = health - grid.get(0).get(0);
    Queue<T> q = new ArrayDeque<>(List.of(new T(0, 0, initialHealth)));
    boolean[][][] seen = new boolean[m][n][health + 1];
    seen[0][0][initialHealth] = true;

    while (!q.isEmpty())
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().i;
        final int j = q.peek().j;
        final int h = q.poll().h;
        if (i == m - 1 && j == n - 1 && h > 0)
          return true;
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k][0];
          final int y = j + dirs[k][1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          final int nextHealth = h - grid.get(x).get(y);
          if (nextHealth <= 0 || seen[x][y][nextHealth])
            continue;
          q.offer(new T(x, y, nextHealth));
          seen[x][y][nextHealth] = true;
        }
      }

    return false;
  }
}
