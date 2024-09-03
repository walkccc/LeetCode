class Solution {
  public int maximumMinimumPath(int[][] grid) {
    record T(int i, int j, int val) {}
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = grid[0][0];
    boolean[][] seen = new boolean[m][n];
    Queue<T> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b.val, a.val));

    maxHeap.offer(new T(0, 0, grid[0][0]));

    while (!maxHeap.isEmpty()) {
      final int i = maxHeap.peek().i;
      final int j = maxHeap.peek().j;
      final int val = maxHeap.poll().val;
      ans = Math.min(ans, val);
      if (i == m - 1 && j == n - 1)
        return ans;
      seen[i][j] = true;
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        maxHeap.offer(new T(x, y, grid[x][y]));
      }
    }

    throw new IllegalArgumentException();
  }
}
