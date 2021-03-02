class Solution {
  public int[] loudAndRich(int[][] richer, int[] quiet) {
    int[] ans = new int[quiet.length];
    List<Integer>[] graph = new List[quiet.length];

    Arrays.fill(ans, -1);

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : richer)
      graph[edge[1]].add(edge[0]);

    for (int i = 0; i < graph.length; ++i)
      dfs(graph, i, quiet, ans);

    return ans;
  }

  private int dfs(List<Integer>[] graph, int node, int[] quiet, int[] ans) {
    if (ans[node] != -1)
      return ans[node];

    ans[node] = node;

    for (final int child : graph[node]) {
      final int res = dfs(graph, child, quiet, ans);
      if (quiet[res] < quiet[ans[node]])
        ans[node] = res;
    }

    return ans[node];
  }
}
