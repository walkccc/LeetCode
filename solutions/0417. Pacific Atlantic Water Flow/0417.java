class Solution {
  public List<List<Integer>> pacificAtlantic(int[][] matrix) {
    if (matrix.length == 0)
      return new ArrayList<>();

    final int m = matrix.length;
    final int n = matrix[0].length;

    List<List<Integer>> ans = new ArrayList<>();
    Queue<int[]> qP = new LinkedList<>();
    Queue<int[]> qA = new LinkedList<>();
    boolean[][] seenP = new boolean[m][n];
    boolean[][] seenA = new boolean[m][n];

    for (int i = 0; i < m; ++i) {
      qP.offer(new int[] {i, 0});
      qA.offer(new int[] {i, n - 1});
      seenP[i][0] = true;
      seenA[i][n - 1] = true;
    }

    for (int j = 0; j < n; ++j) {
      qP.offer(new int[] {0, j});
      qA.offer(new int[] {m - 1, j});
      seenP[0][j] = true;
      seenA[m - 1][j] = true;
    }

    bfs(matrix, qP, seenP);
    bfs(matrix, qA, seenA);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seenP[i][j] && seenA[i][j])
          ans.add(new ArrayList<>(Arrays.asList(i, j)));

    return ans;
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};

  private void bfs(int[][] matrix, Queue<int[]> q, boolean[][] seen) {
    while (!q.isEmpty()) {
      final int i = q.peek()[0];
      final int j = q.poll()[1];
      final int h = matrix[i][j];
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (x < 0 || x == matrix.length || y < 0 || y == matrix[0].length)
          continue;
        if (seen[x][y] || matrix[x][y] < h)
          continue;
        q.offer(new int[] {x, y});
        seen[x][y] = true;
      }
    }
  }
}
