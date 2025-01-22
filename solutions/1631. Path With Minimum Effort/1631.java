class Solution {
  public int minimumEffortPath(int[][] heights) {
    // d := the maximum difference of (i, j) and its neighbors
    record T(int i, int j, int d) {}
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = heights.length;
    final int n = heights[0].length;
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.d, b.d));
    // dist[i][j] := the maximum absolute difference to reach (i, j)
    int[][] diff = new int[m][n];
    Arrays.stream(diff).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    boolean[][] seen = new boolean[m][n];

    minHeap.offer(new T(0, 0, 0));
    diff[0][0] = 0;

    while (!minHeap.isEmpty()) {
      final int i = minHeap.peek().i;
      final int j = minHeap.peek().j;
      final int d = minHeap.poll().d;
      if (i == m - 1 && j == n - 1)
        return d;
      seen[i][j] = true;
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        final int newDiff = Math.abs(heights[i][j] - heights[x][y]);
        final int maxDiff = Math.max(diff[i][j], newDiff);
        if (diff[x][y] > maxDiff) {
          diff[x][y] = maxDiff;
          minHeap.offer(new T(x, y, maxDiff));
        }
      }
    }

    throw new IllegalArgumentException();
  }
}
