class Solution {
  public int shortestBridge(int[][] grid) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int n = grid.length;
    Queue<int[]> q = new ArrayDeque<>();

    markGridTwo(grid, q);

    for (int ans = 0; !q.isEmpty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek()[0];
        final int j = q.poll()[1];
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (grid[x][y] == 2)
            continue;
          if (grid[x][y] == 1)
            return ans;
          grid[x][y] = 2;
          q.offer(new int[] {x, y});
        }
      }

    throw new IllegalArgumentException();
  }

  // Marks one group to 2s by DFS.
  private void markGridTwo(int[][] grid, Queue<int[]> q) {
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] == 1) {
          markGridTwo(grid, i, j, q);
          return;
        }
  }

  // Marks one group to 2s by DFS and pushes them to the queue.
  private void markGridTwo(int[][] grid, int i, int j, Queue<int[]> q) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return;
    if (grid[i][j] != 1)
      return;
    grid[i][j] = 2;
    q.offer(new int[] {i, j});
    markGridTwo(grid, i + 1, j, q);
    markGridTwo(grid, i - 1, j, q);
    markGridTwo(grid, i, j + 1, q);
    markGridTwo(grid, i, j - 1, q);
  }
}
