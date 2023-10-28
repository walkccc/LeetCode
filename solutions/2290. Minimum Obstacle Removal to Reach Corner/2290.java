class Solution {
  public int minimumObstacles(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};
    // (d, i, j)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
    int[][] dist = new int[m][n];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));

    minHeap.offer(new int[] {grid[0][0], 0, 0});
    dist[0][0] = grid[0][0];

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek()[0];
      final int i = minHeap.peek()[1];
      final int j = minHeap.poll()[2];
      if (i == m - 1 && j == n - 1)
        return d;
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        final int newDist = d + grid[i][j];
        if (newDist < dist[x][y]) {
          dist[x][y] = newDist;
          minHeap.offer(new int[] {newDist, x, y});
        }
      }
    }

    return dist[m - 1][n - 1];
  }
}
