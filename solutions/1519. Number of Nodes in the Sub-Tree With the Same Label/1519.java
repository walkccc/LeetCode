class Solution {
  public int[] countSubTrees(int n, int[][] edges, String labels) {
    int[] ans = new int[n];
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    dfs(graph, 0, -1, labels, ans);

    return ans;
  }

  private int[] dfs(List<Integer>[] graph, int u, int parent, final String labels, int[] ans) {
    int[] count = new int[26]; // count of letters down from this u

    for (final int v : graph[u]) {
      if (v == parent)
        continue;
      int[] childCount = dfs(graph, v, u, labels, ans);
      for (int i = 0; i < 26; ++i)
        count[i] += childCount[i];
    }

    ans[u] = ++count[labels.charAt(u) - 'a']; // the u itself
    return count;
  }
}
