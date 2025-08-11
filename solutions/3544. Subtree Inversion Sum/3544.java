class Solution {
  public long subtreeInversionSum(int[][] edges, int[] nums, int k) {
    final int n = edges.length + 1;
    int[] parent = new int[n];
    List<Integer>[] graph = new List[n];
    Arrays.fill(parent, -1);
    Arrays.setAll(graph, i -> new ArrayList<>());

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    return dfs(graph, /*u=*/0, /*stepsSinceInversion=*/k,
               /*inverted=*/false, nums, k, parent, new Long[n][k + 1][2]);
  }

  private long dfs(List<Integer>[] graph, int u, int stepsSinceInversion, boolean inverted,
                   int[] nums, int k, int[] parent, Long[][][] mem) {
    if (mem[u][stepsSinceInversion][inverted ? 1 : 0] != null)
      return mem[u][stepsSinceInversion][inverted ? 1 : 0];
    long num = inverted ? -nums[u] : nums[u];
    long negNum = -num;
    for (final int v : graph[u]) {
      if (v == parent[u])
        continue;
      parent[v] = u;
      num += dfs(graph, v, Math.min(k, stepsSinceInversion + 1), inverted, nums, k, parent, mem);
      if (stepsSinceInversion == k)
        negNum += dfs(graph, v, 1, !inverted, nums, k, parent, mem);
    }
    return mem[u][stepsSinceInversion][inverted ? 1 : 0] =
               (stepsSinceInversion == k) ? Math.max(num, negNum) : num;
  }
}
