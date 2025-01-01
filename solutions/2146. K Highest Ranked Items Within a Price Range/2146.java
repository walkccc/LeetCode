class Solution {
  public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing, int[] start, int k) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = grid.length;
    final int n = grid[0].length;
    final int low = pricing[0];
    final int high = pricing[1];
    final int row = start[0];
    final int col = start[1];
    List<List<Integer>> ans = new ArrayList<>();

    if (low <= grid[row][col] && grid[row][col] <= high) {
      ans.add(Arrays.asList(row, col));
      if (k == 1)
        return ans;
    }

    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(row, col)));
    boolean[][] seen = new boolean[m][n];
    seen[row][col] = true; // Mark as visited.

    while (!q.isEmpty()) {
      List<List<Integer>> neighbors = new ArrayList<>();
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] == 0 || seen[x][y])
            continue;
          if (low <= grid[x][y] && grid[x][y] <= high)
            neighbors.add(Arrays.asList(x, y));
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }
      Collections.sort(neighbors, new Comparator<List<Integer>>() {
        @Override
        public int compare(List<Integer> a, List<Integer> b) {
          final int x1 = a.get(0);
          final int y1 = a.get(1);
          final int x2 = b.get(0);
          final int y2 = b.get(1);
          if (grid[x1][y1] != grid[x2][y2])
            return grid[x1][y1] - grid[x2][y2];
          return x1 == x2 ? y1 - y2 : x1 - x2;
        }
      });
      for (List<Integer> neighbor : neighbors) {
        if (ans.size() < k)
          ans.add(neighbor);
        if (ans.size() == k)
          return ans;
      }
    }

    return ans;
  }
}
