class T {
  public int i;
  public int j;
  public int height;
  public T(int i, int j, int height) {
    this.i = i;
    this.j = j;
    this.height = height;
  }
}

class Solution {
  public int cutOffTree(List<List<Integer>> forest) {
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> a.height - b.height);

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
      // walk from (x, y) to (i, j)
      final int steps = bfs(forest, x, y, i, j);
      if (steps < 0)
        return -1;
      ans += steps;
      x = i;
      y = j;
    }

    return ans;
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};

  private int bfs(List<List<Integer>> forest, int si, int sj, int ei, int ej) {
    final int m = forest.size();
    final int n = forest.get(0).size();
    int steps = 0;
    Queue<int[]> q = new ArrayDeque<>(Arrays.asList(new int[] {si, sj}));
    boolean[][] seen = new boolean[m][n];
    seen[si][sj] = true;

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek()[0];
        final int j = q.poll()[1];
        if (i == ei && j == ej)
          return steps;
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y] || forest.get(x).get(y) == 0)
            continue;
          q.offer(new int[] {x, y});
          seen[x][y] = true;
        }
      }
      ++steps;
    }

    return -1;
  };
}
