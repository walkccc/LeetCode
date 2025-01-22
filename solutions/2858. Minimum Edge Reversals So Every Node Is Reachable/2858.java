class Solution {
  public int[] minEdgeReversals(int n, int[][] edges) {
    int[] ans = new int[n];
    List<Pair<Integer, Boolean>>[] graph = new List[n];
    boolean[] seen = new boolean[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(new Pair<>(v, /*isForward=*/true));
      graph[v].add(new Pair<>(u, /*isForward=*/false));
    }

    Integer[] mem = new Integer[n];
    ans[0] = minEdgeReversals(graph, 0, seen, mem);
    seen = new boolean[n];
    dfs(graph, 0, seen, ans);
    return ans;
  }

  // Returns the minimum number of edge reversals so node u can reach every
  // node in its subtree.
  private int minEdgeReversals(List<Pair<Integer, Boolean>>[] graph, int u, boolean[] seen,
                               Integer[] mem) {
    if (mem[u] != null)
      return mem[u];
    int res = 0;
    seen[u] = true;
    for (Pair<Integer, Boolean> pair : graph[u]) {
      final int v = pair.getKey();
      final boolean isForward = pair.getValue();
      if (seen[v])
        continue;
      seen[v] = true;
      res += minEdgeReversals(graph, v, seen, mem) + (isForward ? 0 : 1);
    }
    return mem[u] = res;
  }

  private void dfs(List<Pair<Integer, Boolean>>[] graph, int u, boolean[] seen, int[] ans) {
    seen[u] = true;
    for (Pair<Integer, Boolean> pair : graph[u]) {
      final int v = pair.getKey();
      final boolean isForward = pair.getValue();
      if (seen[v])
        continue;
      seen[v] = true;
      ans[v] = ans[u] + (isForward ? 1 : -1);
      dfs(graph, v, seen, ans);
    }
  }
}
