class Solution {
  public int[] loudAndRich(int[][] richer, int[] quiet) {
    int[] ans = new int[quiet.length];
    List<Integer>[] graph = new List[quiet.length];

    Arrays.fill(ans, -1);

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] e : richer)
      graph[e[1]].add(e[0]);

    for (int i = 0; i < graph.length; ++i)
      dfs(graph, i, quiet, ans);

    return ans;
  }

  private int dfs(List<Integer>[] graph, int u, int[] quiet, int[] ans) {
    if (ans[u] != -1)
      return ans[u];

    ans[u] = u;

    for (final int v : graph[u]) {
      final int res = dfs(graph, v, quiet, ans);
      if (quiet[res] < quiet[ans[u]])
        ans[u] = res;
    }

    return ans[u];
  }
}
