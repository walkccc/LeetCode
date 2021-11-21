class Solution {
  public int minimumSemesters(int n, int[][] relations) {
    int ans = 0;
    List<Integer>[] graph = new List[n];
    int[] inDegree = new int[n];
    Queue<Integer> q = new LinkedList<>();

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (int[] r : relations) {
      final int u = r[0] - 1;
      final int v = r[1] - 1;
      graph[u].add(v);
      ++inDegree[v];
    }

    // topology
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        q.offer(i);

    while (!q.isEmpty()) {
      for (int size = q.size(); size > 0; --size) {
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
