class Solution {
  public int maximumSafenessFactor(List<List<Integer>> grid) {
    int[][] distToThief = getDistToThief(grid);
    int l = 0;
    int r = grid.size() * 2;

    while (l < r) {
      final int m = (l + r) / 2;
      if (hasValidPath(distToThief, m))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private boolean hasValidPath(int[][] distToThief, int safeness) {
    if (distToThief[0][0] < safeness)
      return false;

    final int n = distToThief.length;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(0, 0)));
    boolean[][] seen = new boolean[n][n];
    seen[0][0] = true;

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      if (distToThief[i][j] < safeness)
        continue;
      if (i == n - 1 && j == n - 1)
        return true;
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == n || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        q.offer(new Pair<>(x, y));
        seen[x][y] = true;
      }
    }

    return false;
  }

  private int[][] getDistToThief(List<List<Integer>> grid) {
    final int n = grid.size();
    int[][] distToThief = new int[n][n];
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();
    boolean[][] seen = new boolean[n][n];

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (grid.get(i).get(j) == 1) {
          q.offer(new Pair<>(i, j));
          seen[i][j] = true;
        }

    for (int dist = 0; !q.isEmpty(); ++dist) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        distToThief[i][j] = dist;
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (seen[x][y])
            continue;
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }
    }

    return distToThief;
  }
}
