class Solution {
  public int latestDayToCross(int row, int col, int[][] cells) {
    int ans = 0;
    int l = 1;
    int r = cells.length - 1;

    while (l <= r) {
      final int m = (l + r) / 2;
      if (canWalk(m, row, col, cells)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans;
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private boolean canWalk(int day, int row, int col, int[][] cells) {
    int[][] matrix = new int[row][col];
    for (int i = 0; i < day; ++i) {
      final int x = cells[i][0] - 1;
      final int y = cells[i][1] - 1;
      matrix[x][y] = 1;
    }

    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();

    for (int j = 0; j < col; ++j)
      if (matrix[0][j] == 0) {
        q.offer(new Pair<>(0, j));
        matrix[0][j] = 1;
      }

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == row || y < 0 || y == col)
          continue;
        if (matrix[x][y] == 1)
          continue;
        if (x == row - 1)
          return true;
        q.offer(new Pair<>(x, y));
        matrix[x][y] = 1;
      }
    }

    return false;
  }
}
