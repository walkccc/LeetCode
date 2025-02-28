class Solution {
  public int[] countSubTrees(int n, int[][] edges, String labels) {
    int[] ans = new int[n];
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(graph, 0, -1, labels, ans);
    return ans;
  }

  private int[] dfs(List<Integer>[] graph, int u, int prev, final String labels, int[] ans) {
    // count[i] := the number of letters down from ('a' + i)
    int[] count = new int[26];

    for (final int v : graph[u]) {
      if (v == prev)
        continue;
      int[] childCount = dfs(graph, v, u, labels, ans);
      for (int i = 0; i < 26; ++i)
        count[i] += childCount[i];
    }

    ans[u] = ++count[labels.charAt(u) - 'a']; // the u itself
    return count;
  }
}
