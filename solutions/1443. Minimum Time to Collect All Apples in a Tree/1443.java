class Solution {
  public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    return dfs(graph, 0, new boolean[n], hasApple);
  }

  private int dfs(List<Integer>[] graph, int u, boolean[] seen, List<Boolean> hasApple) {
    seen[u] = true;
    int totalCost = 0;

    for (final int v : graph[u]) {
      if (seen[v])
        continue;
      final int cost = dfs(graph, v, seen, hasApple);
      if (cost > 0 || hasApple.get(v))
        totalCost += cost + 2;
    }

    return totalCost;
  }
}
