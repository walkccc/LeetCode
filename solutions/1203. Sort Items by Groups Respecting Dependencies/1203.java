class Solution {
  public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
    List<Integer>[] graph = new List[n + m];
    int[] inDegrees = new int[n + m];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    // Build the graph by remapping the k-th group to k + n imaginary node.
    for (int i = 0; i < group.length; ++i) {
      if (group[i] == -1)
        continue;
      graph[group[i] + n].add(i);
      ++inDegrees[i];
    }

    for (int i = 0; i < beforeItems.size(); ++i)
      for (final int b : beforeItems.get(i)) {
        final int u = group[b] == -1 ? b : group[b] + n;
        final int v = group[i] == -1 ? i : group[i] + n;
        if (u == v) { // u and v are already in the same group.
          graph[b].add(i);
          ++inDegrees[i];
        } else {
          graph[u].add(v);
          ++inDegrees[v];
        }
      }

    // Perform topological sorting.
    List<Integer> ans = new ArrayList<>();

    for (int i = 0; i < n + m; ++i)
      if (inDegrees[i] == 0) // inDegrees[i] == -1 means visited.
        dfs(graph, i, inDegrees, n, ans);

    return ans.size() == n ? ans.stream().mapToInt(Integer::intValue).toArray() : new int[] {};
  }

  private void dfs(List<Integer>[] graph, int u, int[] inDegrees, int n, List<Integer> ans) {
    if (u < n)
      ans.add(u);

    inDegrees[u] = -1; // Mark as visited.

    for (final int v : graph[u])
      if (--inDegrees[v] == 0)
        dfs(graph, v, inDegrees, n, ans);
  }
}
