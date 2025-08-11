/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   boolean canMove(char direction);
 *   void move(char direction);
 *   boolean isTarget();
 * }
 */

enum Grid { UNVISITED, START, TARGET, BLOCKED, EMPTY }

class Solution {
  public int findShortestPath(GridMaster master) {
    final int m = 501;
    final int startX = m;
    final int startY = m;
    Grid[][] grid = new Grid[m * 2][m * 2];
    Arrays.stream(grid).forEach(A -> Arrays.fill(A, Grid.UNVISITED));

    // Build the grid information by DFS.
    dfs(master, grid, startX, startY);

    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(startX, startY)));
    grid[startX][startY] = Grid.BLOCKED;

    // Find the steps by BFS.
    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int[] dir : DIRS) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (grid[x][y] == Grid.TARGET)
            return step;
          if (grid[x][y] == Grid.BLOCKED)
            continue;
          grid[x][y] = Grid.BLOCKED;
          q.offer(new Pair<>(x, y));
        }
      }

    return -1;
  }

  private static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  private static final char[] charTable = {'R', 'D', 'L', 'U'};

  private void dfs(GridMaster master, Grid[][] grid, int i, int j) {
    if (grid[i][j] != Grid.UNVISITED)
      return;
    if (master.isTarget())
      grid[i][j] = Grid.TARGET;
    else
      grid[i][j] = Grid.EMPTY;

    for (int k = 0; k < 4; ++k) {
      final int x = i + DIRS[k][0];
      final int y = j + DIRS[k][1];
      final char d = charTable[k];
      final char undoD = charTable[(k + 2) % 4];
      if (master.canMove(d)) {
        master.move(d);
        dfs(master, grid, x, y);
        master.move(undoD);
      } else {
        grid[x][y] = Grid.BLOCKED;
      }
    }
  }
}
