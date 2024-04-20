class Solution {
  public long countPairs(int n, int[][] edges) {
    long ans = 0;
    List<Integer>[] graph = new List[n];
    boolean[] seen = new boolean[n];
    int unreached = n;

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = 0; i < n; ++i) {
      final int reached = dfs(graph, i, seen);
      unreached -= reached;
      ans += (long) unreached * reached;
    }
    return ans;
  }

  private int dfs(List<Integer>[] graph, int u, boolean[] seen) {
    if (seen[u])
      return 0;

    seen[u] = true;
    int ans = 1;
    for (final int v : graph[u])
      ans += dfs(graph, v, seen);
    return ans;
  }
}
