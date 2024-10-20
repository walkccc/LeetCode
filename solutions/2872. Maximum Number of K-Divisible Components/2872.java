class Solution {
  public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(graph, 0, /*prev=*/-1, values, k);
    return ans;
  }

  private int ans = 0;

  private long dfs(List<Integer>[] graph, int u, int prev, int[] values, int k) {
    long treeSum = values[u];

    for (int v : graph[u])
      if (v != prev)
        treeSum += dfs(graph, v, u, values, k);

    if (treeSum % k == 0)
      ++ans;
    return treeSum;
  }
}
