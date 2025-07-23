class Solution {
  public int[][] updateMatrix(int[][] mat) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = mat.length;
    final int n = mat[0].length;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 0)
          q.offer(new Pair<>(i, j));
        else
          mat[i][j] = Integer.MAX_VALUE;

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      for (int[] dir : DIRS) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (mat[x][y] <= mat[i][j] + 1)
          continue;
        q.offer(new Pair<>(x, y));
        mat[x][y] = mat[i][j] + 1;
      }
    }

    return mat;
  }
}
