class Solution {
  public int getFood(char[][] grid) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = grid.length;
    final int n = grid[0].length;
    Queue<int[]> q = new ArrayDeque<>(Arrays.asList(getStartLocation(grid)));

    for (int ans = 0; !q.isEmpty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek()[0];
        final int j = q.poll()[1];
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] == 'X')
            continue;
          if (grid[x][y] == '#')
            return ans + 1;
          q.add(new int[] {x, y});
          grid[x][y] = 'X'; // Mark as visited.
        }
      }

    return -1;
  }

  private int[] getStartLocation(char[][] grid) {
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] == '*')
          return new int[] {i, j};
    throw new IllegalArgumentException();
  }
}
