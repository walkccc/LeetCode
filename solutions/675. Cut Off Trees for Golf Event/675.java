class Solution {
  public int cutOffTree(List<List<Integer>> forest) {
    record T(int i, int j, int height) {}
    Queue<T> minHeap = new PriorityQueue<>(Comparator.comparingInt(T::height));

    for (int i = 0; i < forest.size(); ++i)
      for (int j = 0; j < forest.get(0).size(); ++j)
        if (forest.get(i).get(j) > 1)
          minHeap.offer(new T(i, j, forest.get(i).get(j)));

    int ans = 0;
    int x = 0;
    int y = 0;

    while (!minHeap.isEmpty()) {
      final int i = minHeap.peek().i;
      final int j = minHeap.poll().j;
      // Walk from (x, y) to (i, j).
      final int step = bfs(forest, x, y, i, j);
      if (step < 0)
        return -1;
      ans += step;
      x = i;
      y = j;
    }

    return ans;
  }

  private static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private int bfs(List<List<Integer>> forest, int si, int sj, int ei, int ej) {
    final int m = forest.size();
    final int n = forest.get(0).size();
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(si, sj)));
    boolean[][] seen = new boolean[m][n];
    seen[si][sj] = true;

    for (int step = 0; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        if (i == ei && j == ej)
          return step;
        for (int[] dir : DIRS) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y] || forest.get(x).get(y) == 0)
            continue;
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }

    return -1;
  };
}
