class Solution {
  public int getFood(char[][] grid) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = grid.length;
    final int n = grid[0].length;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(getStartLocation(grid)));

    for (int ans = 0; !q.isEmpty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] == 'X')
            continue;
          if (grid[x][y] == '#')
            return ans + 1;
          q.add(new Pair<>(x, y));
          grid[x][y] = 'X'; // Mark as visited.
        }
      }

    return -1;
  }

  private Pair<Integer, Integer> getStartLocation(char[][] grid) {
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        if (grid[i][j] == '*')
          return new Pair<>(i, j);
    throw new IllegalArgumentException();
  }
}
