class T {
  public int i;
  public int j;
  public int val;

  public T(int i, int j, int val) {
    this.i = i;
    this.j = j;
    this.val = val;
  }
}

class Solution {
  public int maximumMinimumPath(int[][] A) {
    final int m = A.length;
    final int n = A[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};

    int ans = A[0][0];
    boolean[][] seen = new boolean[m][n];
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> b.val - a.val);

    pq.offer(new T(0, 0, A[0][0]));

    while (!pq.isEmpty()) {
      final int i = pq.peek().i;
      final int j = pq.peek().j;
      final int val = pq.poll().val;
      ans = Math.min(ans, val);
      if (i == m - 1 && j == n - 1)
        return ans;
      seen[i][j] = true;
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        pq.offer(new T(x, y, A[x][y]));
      }
    }

    throw new IllegalArgumentException();
  }
}
