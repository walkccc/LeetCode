class Solution {
  public int findShortestCycle(int n, int[][] edges) {
    int ans = INF;
    List<Integer>[] graph = new List[n];
    Arrays.setAll(graph, i -> new ArrayList<>());

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = 0; i < n; ++i)
      ans = Math.min(ans, bfs(graph, i));

    return ans == INF ? -1 : ans;
  }

  private static final int INF = 1001;

  // Returns the length of the minimum cycle by starting BFS from node `i`.
  // Returns `INF` if there's no cycle.
  private int bfs(List<Integer>[] graph, int i) {
    int[] dist = new int[graph.length];
    Arrays.fill(dist, INF);
    Queue<Integer> q = new ArrayDeque<>(List.of(i));
    dist[i] = 0;
    while (!q.isEmpty()) {
      final int u = q.poll();
      for (final int v : graph[u]) {
        if (dist[v] == INF) {
          dist[v] = dist[u] + 1;
          q.offer(v);
        } else if (dist[v] + 1 != dist[u]) { // v is not a parent u.
          return dist[v] + dist[u] + 1;
        }
      }
    }
    return INF;
  }
}
