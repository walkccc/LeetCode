class T {
  public int i;
  public int j;
  public int h; // heightMap[i][j] or the height after filling water
  public T(int i, int j, int h) {
    this.i = i;
    this.j = j;
    this.h = h;
  }
}

class Solution {
  public int trapRainWater(int[][] heightMap) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = heightMap.length;
    final int n = heightMap[0].length;
    int ans = 0;
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.h, b.h));
    boolean[][] seen = new boolean[m][n];

    for (int i = 0; i < m; ++i) {
      minHeap.offer(new T(i, 0, heightMap[i][0]));
      minHeap.offer(new T(i, n - 1, heightMap[i][n - 1]));
      seen[i][0] = true;
      seen[i][n - 1] = true;
    }

    for (int j = 1; j < n - 1; ++j) {
      minHeap.offer(new T(0, j, heightMap[0][j]));
      minHeap.offer(new T(m - 1, j, heightMap[m - 1][j]));
      seen[0][j] = true;
      seen[m - 1][j] = true;
    }

    while (!minHeap.isEmpty()) {
      final int i = minHeap.peek().i;
      final int j = minHeap.peek().j;
      final int h = minHeap.poll().h;
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        if (heightMap[x][y] < h) {
          ans += h - heightMap[x][y];
          minHeap.offer(new T(x, y, h)); // Fill water in grid[x][y].
        } else {
          minHeap.offer(new T(x, y, heightMap[x][y]));
        }
        seen[x][y] = true;
      }
    }

    return ans;
  }
}
