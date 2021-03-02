class T {
  public int i;
  public int j;
  public int height; // grid[i][j]

  public T(int i, int j, int height) {
    this.i = i;
    this.j = j;
    this.height = height;
  }
}

class Solution {
  public int swimInWater(int[][] grid) {
    final int n = grid.length;
    final int[] dirs = {0, 1, 0, -1, 0};

    int ans = grid[0][0];
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> a.height - b.height);
    boolean[][] seen = new boolean[n][n];

    pq.offer(new T(0, 0, grid[0][0]));
    seen[0][0] = true;

    while (!pq.isEmpty()) {
      final int i = pq.peek().i;
      final int j = pq.peek().j;
      final int height = pq.poll().height;
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
        pq.offer(new T(x, y, grid[x][y]));
        seen[x][y] = true;
      }
    }

    return ans;
  }
}
