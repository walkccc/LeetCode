class Solution {
  public int shortestBridge(int[][] A) {
    final int n = A.length;
    final int[] dirs = {0, 1, 0, -1, 0};

    int ans = 0;
    Queue<int[]> q = new LinkedList<>();

    markAsTwo(A, q);

    // expand by BFS
    while (!q.isEmpty()) {
      for (int size = q.size(); size > 0; --size) {
        final int i = q.peek()[0];
        final int j = q.poll()[1];
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (A[x][y] == 2)
            continue;
          if (A[x][y] == 1)
            return ans;
          A[x][y] = 2;
          q.offer(new int[] {x, y});
        }
      }
      ++ans;
    }

    throw new IllegalArgumentException();
  }

  // mark one group to 2s by DFS
  private void markAsTwo(int[][] A, Queue<int[]> q) {
    for (int i = 0; i < A.length; ++i)
      for (int j = 0; j < A[0].length; ++j)
        if (A[i][j] == 1) {
          markAsTwo(A, i, j, q);
          return;
        }
  }

  // mark one group to 2s by DFS and push them to the q
  private void markAsTwo(int[][] A, int i, int j, Queue<int[]> q) {
    if (i < 0 || i == A.length || j < 0 || j == A[0].length)
      return;
    if (A[i][j] != 1)
      return;

    A[i][j] = 2;
    q.offer(new int[] {i, j});
    markAsTwo(A, i + 1, j, q);
    markAsTwo(A, i - 1, j, q);
    markAsTwo(A, i, j + 1, q);
    markAsTwo(A, i, j - 1, q);
  }
}
