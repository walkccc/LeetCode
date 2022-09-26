class Solution {
  public int minimumSemesters(int n, int[][] relations) {
    int ans = 0;
    List<Integer>[] graph = new List[n];
    int[] inDegree = new int[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (int[] r : relations) {
      final int u = r[0] - 1;
      final int v = r[1] - 1;
      graph[u].add(v);
      ++inDegree[v];
    }

    // topology
    Queue<Integer> q = IntStream.range(0, n)
                           .filter(i -> inDegree[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.poll();
        --n;
        for (final int v : graph[u])
          if (--inDegree[v] == 0)
            q.offer(v);
      }
      ++ans;
    }

    return n == 0 ? ans : -1;
  }
}
