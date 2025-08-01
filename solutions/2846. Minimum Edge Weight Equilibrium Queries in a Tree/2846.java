class Solution {
  public int[] minOperationsQueries(int n, int[][] edges, int[][] queries) {
    final int MAX = 26;
    final int m = (int) Math.ceil(Math.log(n) / Math.log(2));
    int[] ans = new int[queries.length];
    List<Pair<Integer, Integer>>[] graph = new List[n];
    // jump[i][j] := the 2^j-th ancestor of i
    int[][] jump = new int[n][m];
    // depth[i] := the depth of i
    int[] depth = new int[n];
    // count[i][j] := the count of j from root to i, where 1 <= j <= 26
    int[][] count = new int[n][MAX + 1];
    Arrays.setAll(graph, i -> new ArrayList<>());

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    count[0] = new int[MAX + 1];
    dfs(graph, 0, /*prev=*/-1, jump, depth, count);

    for (int j = 1; j < m; ++j)
      for (int i = 0; i < n; ++i)
        jump[i][j] = jump[jump[i][j - 1]][j - 1];

    for (int i = 0; i < queries.length; ++i) {
      final int u = queries[i][0];
      final int v = queries[i][1];
      final int lca = getLCA(u, v, jump, depth);
      // the number of edges between (u, v).
      final int numEdges = depth[u] + depth[v] - 2 * depth[lca];
      // the maximum frequency of edges between (u, v)
      int maxFreq = 0;
      for (int j = 1; j <= MAX; ++j)
        maxFreq = Math.max(maxFreq, count[u][j] + count[v][j] - 2 * count[lca][j]);
      ans[i] = numEdges - maxFreq;
    }

    return ans;
  }

  private void dfs(List<Pair<Integer, Integer>>[] graph, int u, int prev, int[][] jump, int[] depth,
                   int[][] count) {
    for (Pair<Integer, Integer> pair : graph[u]) {
      final int v = pair.getKey();
      final int w = pair.getValue();
      if (v == prev)
        continue;
      jump[v][0] = u;
      depth[v] = depth[u] + 1;
      count[v] = count[u].clone();
      ++count[v][w];
      dfs(graph, v, u, jump, depth, count);
    }
  }

  // Returns the lca(u, v) by binary jump.
  private int getLCA(int u, int v, int[][] jump, int[] depth) {
    // v is always deeper than u.
    if (depth[u] > depth[v])
      return getLCA(v, u, jump, depth);
    // Jump v to the same height of u.
    for (int j = 0; j < jump[0].length; ++j)
      if ((depth[v] - depth[u] >> j & 1) == 1)
        v = jump[v][j];
    if (u == v)
      return u;
    // Jump u and v to the node right below the lca.
    for (int j = jump[0].length - 1; j >= 0; --j)
      if (jump[u][j] != jump[v][j]) {
        u = jump[u][j];
        v = jump[v][j];
      }
    return jump[v][0];
  }
}
