class Solution {
  public int[] assignEdgeWeights(int[][] edges, int[][] queries) {
    final int n = edges.length + 1;
    int[] ans = new int[queries.length];
    final int[] depth = new int[n + 1];
    final int[][] parent = new int[LOG][n + 1];
    List<Integer>[] graph = new List[n + 1];
    Arrays.setAll(graph, i -> new ArrayList<>());

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(1, -1, graph, parent, depth);

    for (int k = 1; k < LOG; ++k)
      for (int v = 1; v <= n; ++v)
        if (parent[k - 1][v] != -1)
          parent[k][v] = parent[k - 1][parent[k - 1][v]];

    for (int i = 0; i < queries.length; ++i) {
      final int u = queries[i][0];
      final int v = queries[i][1];
      if (u == v) {
        ans[i] = 0;
      } else {
        final int a = lca(u, v, parent, depth);
        final int d = depth[u] + depth[v] - 2 * depth[a];
        ans[i] = modPow(2, d - 1);
      }
    }

    return ans;
  }

  private static final int MOD = 1_000_000_007;
  private static final int LOG = 17; // since 2^17 > 1e5

  private void dfs(int u, int p, java.util.List<Integer>[] graph, int[][] parent, int[] depth) {
    parent[0][u] = p;
    for (int v : graph[u]) {
      if (v != p) {
        depth[v] = depth[u] + 1;
        dfs(v, u, graph, parent, depth);
      }
    }
  }

  private int lca(int u, int v, int[][] parent, int[] depth) {
    if (depth[u] < depth[v]) {
      final int temp = u;
      u = v;
      v = temp;
    }

    for (int k = LOG - 1; k >= 0; --k)
      if (parent[k][u] != -1 && depth[parent[k][u]] >= depth[v])
        u = parent[k][u];

    if (u == v)
      return u;

    for (int k = LOG - 1; k >= 0; --k)
      if (parent[k][u] != -1 && parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }

    return parent[0][u];
  }

  private int modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return (int) (x * modPow(x % MOD, (n - 1)) % MOD);
    return modPow(x * x % MOD, (n / 2)) % MOD;
  }
}
