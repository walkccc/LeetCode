class Solution {
  public int[][] updateMatrix(int[][] mat) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = mat.length;
    final int n = mat[0].length;
    Queue<int[]> q = new ArrayDeque<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 0)
          q.offer(new int[] {i, j});
        else
          mat[i][j] = Integer.MAX_VALUE;

    while (!q.isEmpty()) {
      final int i = q.peek()[0];
      final int j = q.poll()[1];
      for (int[] dir : dirs) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (mat[x][y] <= mat[i][j] + 1)
          continue;
        q.offer(new int[] {x, y});
        mat[x][y] = mat[i][j] + 1;
      }
    }

    return mat;
  }
}
