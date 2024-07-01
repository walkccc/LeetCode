enum Pos { kHorizontal, kVertical }

class Solution {
  public int minimumMoves(int[][] grid) {
    final int n = grid.length;
    int ans = 0;
    // the state of (x, y, pos)
    // pos := 0 (horizontal) / 1 (vertical)
    Queue<int[]> q = new ArrayDeque<>(Arrays.asList(new int[] {0, 0, Pos.kHorizontal.ordinal()}));
    boolean[][][] seen = new boolean[n][n][2];
    seen[0][0][Pos.kHorizontal.ordinal()] = true;

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int x = q.peek()[0];
        final int y = q.peek()[1];
        final int pos = q.poll()[2];
        if (x == n - 1 && y == n - 2 && pos == Pos.kHorizontal.ordinal())
          return ans;
        if (canMoveRight(grid, x, y, pos) && !seen[x][y + 1][pos]) {
          q.offer(new int[] {x, y + 1, pos});
          seen[x][y + 1][pos] = true;
        }
        if (canMoveDown(grid, x, y, pos) && !seen[x + 1][y][pos]) {
          q.offer(new int[] {x + 1, y, pos});
          seen[x + 1][y][pos] = true;
        }
        final int newPos =
            pos == Pos.kHorizontal.ordinal() ? Pos.kVertical.ordinal() : Pos.kHorizontal.ordinal();
        if ((canRotateClockwise(grid, x, y, pos) || canRotateCounterclockwise(grid, x, y, pos)) &&
            !seen[x][y][newPos]) {
          q.offer(new int[] {x, y, newPos});
          seen[x][y][newPos] = true;
        }
      }
      ++ans;
    }

    return -1;
  }

  private boolean canMoveRight(int[][] grid, int x, int y, int pos) {
    if (pos == Pos.kHorizontal.ordinal())
      return y + 2 < grid.length && grid[x][y + 2] == 0;
    return y + 1 < grid.length && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0;
  }

  private boolean canMoveDown(int[][] grid, int x, int y, int pos) {
    if (pos == Pos.kVertical.ordinal())
      return x + 2 < grid.length && grid[x + 2][y] == 0;
    return x + 1 < grid.length && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0;
  };

  private boolean canRotateClockwise(int[][] grid, int x, int y, int pos) {
    return pos == Pos.kHorizontal.ordinal() && x + 1 < grid.length && grid[x + 1][y + 1] == 0 &&
        grid[x + 1][y] == 0;
  };

  private boolean canRotateCounterclockwise(int[][] grid, int x, int y, int pos) {
    return pos == Pos.kVertical.ordinal() && y + 1 < grid.length && grid[x + 1][y + 1] == 0 &&
        grid[x][y + 1] == 0;
  };
}
