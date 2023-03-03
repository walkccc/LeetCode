class Solution {
  public int maxDistance(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();
    int water = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0)
          ++water;
        else
          q.offer(new Pair<>(i, j));

    if (water == 0 || water == m * n)
      return -1;

    int ans = 0;

    for (int d = 0; !q.isEmpty(); ++d)
      for (int sz = q.size(); sz > 0; --sz) {
        Pair<Integer, Integer> pair = q.poll();
        final int i = pair.getKey();
        final int j = pair.getValue();
        ans = d;
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] > 0)
            continue;
          q.offer(new Pair<>(x, y));
          grid[x][y] = 2; // Mark as visited.
        }
      }

    return ans;
  }
}
