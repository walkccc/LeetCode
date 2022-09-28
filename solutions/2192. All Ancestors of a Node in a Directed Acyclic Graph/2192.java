class Solution {
  public List<List<Integer>> getAncestors(int n, int[][] edges) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i) {
      ans.add(new ArrayList<>());
      graph[i] = new ArrayList<>();
    }

    for (int[] e : edges)
      graph[e[0]].add(e[1]);

    for (int i = 0; i < n; ++i)
      dfs(graph, i, i, new boolean[n], ans);

    return ans;
  }

  private void dfs(List<Integer>[] graph, int u, int ancestor, boolean[] seen,
                   List<List<Integer>> ans) {
    seen[u] = true;
    for (final int v : graph[u]) {
      if (seen[v])
        continue;
      ans.get(v).add(ancestor);
      dfs(graph, v, ancestor, seen, ans);
    }
  }
}
