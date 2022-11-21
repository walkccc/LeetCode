class Solution {
  public int swimInWater(int[][] grid) {
    final int n = grid.length;
    final int[] dirs = {0, 1, 0, -1, 0};
    int ans = grid[0][0];
    // (grid[i][j], i, j)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
    boolean[][] seen = new boolean[n][n];

    minHeap.offer(new int[] {grid[0][0], 0, 0});
    seen[0][0] = true;

    while (!minHeap.isEmpty()) {
      final int height = minHeap.peek()[0];
      final int i = minHeap.peek()[1];
      final int j = minHeap.poll()[2];
      ans = Math.max(ans, height);
      if (i == n - 1 && j == n - 1)
        break;
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
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
