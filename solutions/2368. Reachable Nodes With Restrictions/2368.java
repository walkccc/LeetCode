class Solution {
  public int reachableNodes(int n, int[][] edges, int[] restricted) {
    List<Integer>[] graph = new List[n];
    boolean[] seen = new boolean[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (final int r : restricted)
      seen[r] = true;

    return dfs(graph, 0, seen);
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
