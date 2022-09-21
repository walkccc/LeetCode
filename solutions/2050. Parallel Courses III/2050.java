class Solution {
  public int minimumTime(int n, int[][] relations, int[] time) {
    List<Integer>[] graph = new List[n];
    int[] inDegree = new int[n];
    int[] dist = time.clone();

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
