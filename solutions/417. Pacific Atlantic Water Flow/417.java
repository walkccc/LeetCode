class Solution {
  public List<List<Integer>> pacificAtlantic(int[][] heights) {
    final int m = heights.length;
    final int n = heights[0].length;
    List<List<Integer>> ans = new ArrayList<>();
    Queue<Pair<Integer, Integer>> qP = new ArrayDeque<>();
    Queue<Pair<Integer, Integer>> qA = new ArrayDeque<>();
    boolean[][] seenP = new boolean[m][n];
    boolean[][] seenA = new boolean[m][n];

    for (int i = 0; i < m; ++i) {
      qP.offer(new Pair<>(i, 0));
      qA.offer(new Pair<>(i, n - 1));
      seenP[i][0] = true;
      seenA[i][n - 1] = true;
    }

    for (int j = 0; j < n; ++j) {
      qP.offer(new Pair<>(0, j));
      qA.offer(new Pair<>(m - 1, j));
      seenP[0][j] = true;
      seenA[m - 1][j] = true;
    }

    bfs(heights, qP, seenP);
    bfs(heights, qA, seenA);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seenP[i][j] && seenA[i][j])
          ans.add(new ArrayList<>(List.of(i, j)));

    return ans;
  }

  private static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private void bfs(int[][] heights, Queue<Pair<Integer, Integer>> q, boolean[][] seen) {
    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      final int h = heights[i][j];
      for (int[] dir : DIRS) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == heights.length || y < 0 || y == heights[0].length)
          continue;
        if (seen[x][y] || heights[x][y] < h)
          continue;
        q.offer(new Pair<>(x, y));
        seen[x][y] = true;
      }
    }
  }
}
