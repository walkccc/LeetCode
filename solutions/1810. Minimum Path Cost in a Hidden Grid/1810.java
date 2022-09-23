/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *     boolean canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * }
 */

class Solution {
  public int findShortestPath(GridMaster master) {
    final int m = 100;
    final int startX = m;
    final int startY = m;

    int[] target = {m * 2, m * 2};
    int[][] grid = new int[m * 2][m * 2];
    boolean[][] seen = new boolean[m * 2][m * 2];
    Arrays.stream(grid).forEach(A -> Arrays.fill(A, -1));

    // build the grid information by dfs
    dfs(master, grid, startX, startY, target);

    PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[2] - b[2]);
    minHeap.offer(new int[] {startX, startY, 0});

    // find the steps by bfs
    while (!minHeap.isEmpty()) {
      final int i = minHeap.peek()[0];
      final int j = minHeap.peek()[1];
      final int cost = minHeap.poll()[2];
      if (i == target[0] && j == target[1])
        return cost;
      if (seen[i][j])
        continue;
      seen[i][j] = true;
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (x < 0 || x == 2 * m || y < 0 || y == 2 * m)
          continue;
        if (seen[x][y] || grid[x][y] == -1)
          continue;
        final int nextCost = cost + grid[x][y];
        minHeap.offer(new int[] {x, y, nextCost});
      }
    }

    return -1;
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};
  private static final char[] charTable = {'R', 'D', 'L', 'U'};

  private void dfs(GridMaster master, int[][] grid, int i, int j, int[] target) {
    if (master.isTarget()) {
      target[0] = i;
      target[1] = j;
    }

    for (int k = 0; k < 4; ++k) {
      final int x = i + dirs[k];
      final int y = j + dirs[k + 1];
      final char d = charTable[k];
      final char undoD = charTable[(k + 2) % 4];
      if (master.canMove(d) && grid[x][y] == -1) {
        grid[x][y] = master.move(d);
        dfs(master, grid, x, y, target);
        master.move(undoD);
      }
    }
  }
}
