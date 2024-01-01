class Solution {
  public int minTrioDegree(int n, int[][] edges) {
    int ans = Integer.MAX_VALUE;
    Set<Integer>[] graph = new Set[n];
    int[] degrees = new int[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new HashSet<>();

    for (int[] edge : edges) {
      final int u = edge[0] - 1;
      final int v = edge[1] - 1;
      // Store the mapping from `min(u, v)` to `max(u, v)` to speed up.
      graph[Math.min(u, v)].add(Math.max(u, v));
      ++degrees[u];
      ++degrees[v];
    }

    for (int u = 0; u < n; u++)
      for (final int v : graph[u])
        for (final int w : graph[u])
          if (graph[v].contains(w))
            ans = Math.min(ans, degrees[u] + degrees[v] + degrees[w] - 6);

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
