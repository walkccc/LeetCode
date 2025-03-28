class Solution {
  public int numIslands(char[][] grid) {
    int ans = 0;

    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] == '1') {
          bfs(grid, i, j);
          ++ans;
        }

    return ans;
  }

  private static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private void bfs(char[][] grid, int r, int c) {
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(r, c)));
    grid[r][c] = '2'; // Mark '2' as visited.
    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      for (int[] dir : DIRS) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == grid.length || y < 0 || y == grid[0].length)
          continue;
        if (grid[x][y] != '1')
          continue;
        q.offer(new Pair<>(x, y));
        grid[x][y] = '2'; // Mark '2' as visited.
      }
    }
  }
}
