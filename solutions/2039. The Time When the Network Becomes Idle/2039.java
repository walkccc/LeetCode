class Solution {
  public int networkBecomesIdle(int[][] edges, int[] patience) {
    final int n = patience.length;
    int ans = 0;
    List<Integer>[] graph = new List[n];
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(0));
    int[] dist = new int[n]; // dist[i] := the distance between i and 0
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[0] = 0;

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.poll();
        for (final int v : graph[u])
          if (dist[v] == Integer.MAX_VALUE) {
            dist[v] = dist[u] + 1;
            q.offer(v);
          }
      }
    }

    for (int i = 1; i < n; ++i) {
      final int numResending = (dist[i] * 2 - 1) / patience[i];
      final int lastResendingTime = patience[i] * numResending;
      final int lastArrivingTime = lastResendingTime + dist[i] * 2;
      ans = Math.max(ans, lastArrivingTime);
    }

    return ans + 1;
  }
}
