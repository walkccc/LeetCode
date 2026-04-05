class Solution {
  public int swimInWater(int[][] grid) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int n = grid.length;
    int ans = grid[0][0];
    Queue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0])) {
      { offer(new int[] {grid[0][0], 0, 0}); } // (grid[i][j], i, j)
    };
    boolean[][] seen = new boolean[n][n];
    seen[0][0] = true;

    while (!minHeap.isEmpty()) {
      final int height = minHeap.peek()[0];
      final int i = minHeap.peek()[1];
      final int j = minHeap.poll()[2];
      ans = Math.max(ans, height);
      if (i == n - 1 && j == n - 1)
        break;
      for (int[] dir : DIRS) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == n || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        minHeap.offer(new int[] {grid[x][y], x, y});
        seen[x][y] = true;
      }
    }

    return ans;
  }
}
