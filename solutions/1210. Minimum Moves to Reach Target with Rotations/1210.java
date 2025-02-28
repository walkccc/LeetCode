enum Pos { kHorizontal, kVertical }

class Solution {
  public int minimumMoves(int[][] grid) {
    record T(int x, int y, Pos pos) {}
    final int n = grid.length;
    Queue<T> q = new ArrayDeque<>(List.of(new T(0, 0, Pos.kHorizontal)));
    boolean[][][] seen = new boolean[n][n][2];
    seen[0][0][Pos.kHorizontal.ordinal()] = true;

    for (int step = 0; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int x = q.peek().x;
        final int y = q.peek().y;
        final Pos pos = q.poll().pos;
        if (x == n - 1 && y == n - 2 && pos == Pos.kHorizontal)
          return step;
        if (canMoveRight(grid, x, y, pos) && !seen[x][y + 1][pos.ordinal()]) {
          q.offer(new T(x, y + 1, pos));
          seen[x][y + 1][pos.ordinal()] = true;
        }
        if (canMoveDown(grid, x, y, pos) && !seen[x + 1][y][pos.ordinal()]) {
          q.offer(new T(x + 1, y, pos));
          seen[x + 1][y][pos.ordinal()] = true;
        }
        final Pos newPos = pos == Pos.kHorizontal ? Pos.kVertical : Pos.kHorizontal;
        if ((canRotateClockwise(grid, x, y, pos) || canRotateCounterclockwise(grid, x, y, pos)) &&
            !seen[x][y][newPos.ordinal()]) {
          q.offer(new T(x, y, newPos));
          seen[x][y][newPos.ordinal()] = true;
        }
      }

    return -1;
  }

  private boolean canMoveRight(int[][] grid, int x, int y, Pos pos) {
    if (pos == Pos.kHorizontal)
      return y + 2 < grid.length && grid[x][y + 2] == 0;
    return y + 1 < grid.length && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0;
  }

  private boolean canMoveDown(int[][] grid, int x, int y, Pos pos) {
    if (pos == Pos.kVertical)
      return x + 2 < grid.length && grid[x + 2][y] == 0;
    return x + 1 < grid.length && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0;
  }

  private boolean canRotateClockwise(int[][] grid, int x, int y, Pos pos) {
    return pos == Pos.kHorizontal && x + 1 < grid.length && grid[x + 1][y + 1] == 0 &&
        grid[x + 1][y] == 0;
  }

  private boolean canRotateCounterclockwise(int[][] grid, int x, int y, Pos pos) {
    return pos == Pos.kVertical && y + 1 < grid.length && grid[x + 1][y + 1] == 0 &&
        grid[x][y + 1] == 0;
  }
}
