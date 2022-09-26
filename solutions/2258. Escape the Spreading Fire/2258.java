class Solution {
  public int maximumMinutes(int[][] grid) {
    final int[] dirs = {0, 1, 0, -1, 0};
    final int kMax = grid.length * grid[0].length;
    int[][] fireMinute = new int[grid.length][grid[0].length];
    Arrays.stream(fireMinute).forEach(A -> Arrays.fill(A, -1));
    buildFireGrid(grid, fireMinute, dirs);

    int ans = -1;
    int l = 0;
    int r = kMax;

    while (l <= r) {
      final int m = (l + r) / 2;
      if (canStayFor(grid, fireMinute, m, dirs)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans == kMax ? (int) 1e9 : ans;
  }

  private void buildFireGrid(int[][] grid, int[][] fireMinute, final int[] dirs) {
    int minuteFromFire = 0;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();

    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] == 1) { // fire
          q.offer(new Pair<>(i, j));
          fireMinute[i][j] = 0;
        }

    while (!q.isEmpty()) {
      ++minuteFromFire;
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == grid.length || y < 0 || y == grid[0].length)
            continue;
          if (grid[x][y] == 2) // wall
            continue;
          if (fireMinute[x][y] != -1)
            continue;
          fireMinute[x][y] = minuteFromFire;
          q.offer(new Pair<>(x, y));
        }
      }
    }
  }

  boolean canStayFor(int[][] grid, int[][] fireMinute, int minute, final int[] dirs) {
    Queue<Pair<Integer, Integer>> q =
        new ArrayDeque<>(Arrays.asList(new Pair<>(0, 0))); // start position
    boolean[][] seen = new boolean[grid.length][grid[0].length];
    seen[0][0] = true;

    while (!q.isEmpty()) {
      ++minute;
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == grid.length || y < 0 || y == grid[0].length)
            continue;
          if (grid[x][y] == 2) // wall
            continue;
          if (x == grid.length - 1 && y == grid[0].length - 1) {
            if (fireMinute[x][y] != -1 && fireMinute[x][y] < minute)
              continue;
            return true;
          }
          if (fireMinute[x][y] != -1 && fireMinute[x][y] <= minute)
            continue;
          if (seen[x][y])
            continue;
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }
    }

    return false;
  }
}
