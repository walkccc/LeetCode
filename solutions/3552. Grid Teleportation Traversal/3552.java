class Solution {
  // Similar to 3341. Find Minimum Time to Reach Last Room I
  public int minMoves(String[] matrix) {
    if (matrix[matrix.length - 1].charAt(matrix[0].length() - 1) == '#')
      return -1;

    List<Pair<Integer, Integer>>[] teleportPositions = new ArrayList[26];

    for (int i = 0; i < 26; ++i)
      teleportPositions[i] = new ArrayList<>();

    for (int i = 0; i < matrix.length; ++i)
      for (int j = 0; j < matrix[0].length(); ++j) {
        final char c = matrix[i].charAt(j);
        if (c != '.' && c != '#')
          teleportPositions[c - 'A'].add(new Pair<>(i, j));
      }

    return dijkstra(matrix, teleportPositions, new Pair<>(0, 0),
                    new Pair<>(matrix.length - 1, matrix[0].length() - 1));
  }

  private int dijkstra(String[] matrix, List<Pair<Integer, Integer>>[] teleportPositions,
                       Pair<Integer, Integer> src, Pair<Integer, Integer> dst) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = matrix.length;
    final int n = matrix[0].length();
    int[][] dist = new int[m][n];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    boolean[] seen = new boolean[26];

    dist[0][0] = 0;
    Queue<Pair<Integer, Pair<Integer, Integer>>> minHeap =
        new PriorityQueue<>(Comparator.comparingInt(Pair::getKey)) {
          { offer(new Pair<>(dist[0][0], src)); } // (d, u)
        };

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek().getKey();
      final Pair<Integer, Integer> u = minHeap.poll().getValue();
      if (u.equals(dst))
        return d;
      final int i = u.getKey();
      final int j = u.getValue();
      if (d > dist[i][j])
        continue;
      final char c = matrix[i].charAt(j);
      if (Character.isUpperCase(c) && !seen[c - 'A']) {
        seen[c - 'A'] = true;
        for (Pair<Integer, Integer> pos : teleportPositions[c - 'A']) {
          final int x = pos.getKey();
          final int y = pos.getValue();
          if (d < dist[x][y]) {
            dist[x][y] = d;
            minHeap.offer(new Pair<>(d, new Pair<>(x, y)));
          }
        }
      }
      for (int[] dir : DIRS) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (matrix[x].charAt(y) == '#')
          continue;
        if (d + 1 < dist[x][y]) {
          dist[x][y] = d + 1;
          minHeap.offer(new Pair<>(d + 1, new Pair<>(x, y)));
        }
      }
    }

    return -1;
  }
}
