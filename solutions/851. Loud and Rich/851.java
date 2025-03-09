class Solution {
  public int[] loudAndRich(int[][] richer, int[] quiet) {
    final int n = quiet.length;
    int[] ans = new int[n];
    List<Integer>[] graph = new List[n];

    Arrays.fill(ans, -1);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] r : richer) {
      final int u = r[1];
      final int v = r[0];
      graph[u].add(v);
    }

    for (int i = 0; i < n; ++i)
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
