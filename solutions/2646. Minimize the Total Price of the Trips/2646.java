class Solution {
  public int minimumTotalPrice(int n, int[][] edges, int[] price, int[][] trips) {
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    // count[i] := the number of times node i is traversed
    int[] count = new int[n];
    for (int[] trip : trips) {
      final int start = trip[0];
      final int end = trip[1];
      dfsCount(graph, start, -1, end, count, /*path=*/new ArrayList<>());
    }

    Integer[][] mem = new Integer[n][2];
    return dfs(graph, 0, -1, price, count, false, mem);
  }

  private void dfsCount(List<Integer>[] graph, int u, int prev, int end, int[] count,
                        List<Integer> path) {
    path.add(u);
    if (u == end) {
      for (final int i : path)
        ++count[i];
      return;
    }
    for (final int v : graph[u])
      if (v != prev)
        dfsCount(graph, v, u, end, count, path);
    path.remove(path.size() - 1);
  }

  // Returns the minimum price sum for the i-th node, where its parent is
  // halved parent or not halved not.
  private int dfs(List<Integer>[] graph, int u, int prev, int[] price, int[] count,
                  boolean parentHalved, Integer[][] mem) {
    if (mem[u][parentHalved ? 1 : 0] != null)
      return mem[u][parentHalved ? 1 : 0];

    int sumWithFullNode = price[u] * count[u];
    for (final int v : graph[u])
      if (v != prev)
        sumWithFullNode += dfs(graph, v, u, price, count, false, mem);

    if (parentHalved) // Can't halve this node if its parent was halved.
      return mem[u][1] = sumWithFullNode;

    int sumWithHalvedNode = (price[u] / 2) * count[u];
    for (int v : graph[u])
      if (v != prev)
        sumWithHalvedNode += dfs(graph, v, u, price, count, true, mem);

    return mem[u][parentHalved ? 1 : 0] = Math.min(sumWithFullNode, sumWithHalvedNode);
  }
}
