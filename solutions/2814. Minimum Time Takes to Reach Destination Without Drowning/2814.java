class Solution {
  public int minimumSeconds(List<List<String>> land) {
    final int m = land.size();
    final int n = land.get(0).size();
    final int[][] floodDist = getFloodDist(land);
    Queue<Pair<Integer, Integer>> q = new LinkedList<>();
    boolean[][] seen = new boolean[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (land.get(i).get(j).equals("S")) {
          q.offer(new Pair<>(i, j));
          seen[i][j] = true;
        }

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (land.get(x).get(y).equals("D"))
            return step;
          if (floodDist[x][y] <= step || land.get(x).get(y).equals("X") || seen[x][y])
            continue;
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }

    return -1;
  }

  private final int[] dirs = {0, 1, 0, -1, 0};

  private int[][] getFloodDist(List<List<String>> land) {
    final int m = land.size();
    final int n = land.get(0).size();
    int[][] dist = new int[m][n];
    Queue<Pair<Integer, Integer>> q = new LinkedList<>();
    boolean[][] seen = new boolean[m][n];

    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (land.get(i).get(j).equals("*")) {
          q.offer(new Pair<>(i, j));
          seen[i][j] = true;
        }

    for (int d = 0; !q.isEmpty(); ++d)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        dist[i][j] = d;
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (land.get(x).get(y).equals("X") || land.get(x).get(y).equals("D") || seen[x][y])
            continue;
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }

    return dist;
  }
}
