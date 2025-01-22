class Solution {
  public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
    final int n = edges1.length + 1;
    final int m = edges2.length + 1;
    List<Integer>[] graph1 = buildGraph(edges1, n);
    List<Integer>[] graph2 = buildGraph(edges2, m);
    boolean[] parity1 = new boolean[n];
    boolean[] parity2 = new boolean[m]; // Placeholder (not used)
    final int even1 = dfs(graph1, 0, -1, parity1, true);
    final int even2 = dfs(graph2, 0, -1, parity2, true);
    final int odd1 = n - even1;
    final int odd2 = m - even2;
    int[] ans = new int[n];

    for (int i = 0; i < n; i++) {
      final int tree1 = parity1[i] ? even1 : odd1;
      // Can connect the current node in tree1 to either an even or an odd node
      // in tree2.
      final int tree2 = Math.max(even2, odd2);
      ans[i] = tree1 + tree2;
    }

    return ans;
  }

  // Returns the number of nodes that can be reached from u with even steps.
  private int dfs(List<Integer>[] graph, int u, int prev, boolean[] parity, boolean isEven) {
    int res = isEven ? 1 : 0;
    parity[u] = isEven;
    for (final int v : graph[u])
      if (v != prev)
        res += dfs(graph, v, u, parity, !isEven);
    return res;
  }

  private List<Integer>[] buildGraph(int[][] edges, int n) {
    List<Integer>[] graph = new ArrayList[n];
    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();
    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }
    return graph;
  }
}
