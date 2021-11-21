class Solution {
  public int minimumTime(int n, int[][] relations, int[] time) {
    List<Integer>[] graph = new List[n];
    int[] inDegree = new int[n];
    Queue<Integer> q = new LinkedList<>();
    int[] dist = time.clone();

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
      final int u = q.poll();
      for (final int v : graph[u]) {
        dist[v] = Math.max(dist[v], dist[u] + time[v]);
        if (--inDegree[v] == 0)
          q.offer(v);
      }
    }

    return Arrays.stream(dist).max().getAsInt();
  }
}
