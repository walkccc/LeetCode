class Solution {
  public int minimumSemesters(int n, int[][] relations) {
    List<Integer>[] graph = new List[n];
    int[] inDegrees = new int[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    // Build the graph.
    for (int[] relation : relations) {
      final int u = relation[0] - 1;
      final int v = relation[1] - 1;
      graph[u].add(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    Queue<Integer> q = IntStream.range(0, n)
                           .filter(i -> inDegrees[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    int step = 0;
    for (; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.poll();
        --n;
        for (final int v : graph[u])
          if (--inDegrees[v] == 0)
            q.offer(v);
      }

    return n == 0 ? step : -1;
  }
}
