class Solution {
  public int shortestPathBinaryMatrix(int[][] grid) {
    final int n = grid.length;
    if (grid[0][0] == 0 && n == 1)
      return 1;
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;

    final int[][] DIRS = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(0, 0)));
    boolean[][] seen = new boolean[n][n];
    seen[0][0] = true;

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int[] dir : DIRS) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (grid[x][y] != 0 || seen[x][y])
            continue;
          if (x == n - 1 && y == n - 1)
            return step + 1;
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }

    return -1;
  }
}
