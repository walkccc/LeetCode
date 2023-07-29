class Solution {
  public int minReorder(int n, int[][] connections) {
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] conn : connections) {
      graph[conn[0]].add(conn[1]);
      graph[conn[1]].add(-conn[0]); // - := conn[0] -> conn[1]
    }

    return dfs(graph, 0, -1);
  }

  private int dfs(List<Integer>[] graph, int u, int parent) {
    int change = 0;

    for (final int v : graph[u]) {
      if (Math.abs(v) == parent)
        continue;
      if (v > 0)
        ++change;
      change += dfs(graph, Math.abs(v), u);
    }

    return change;
  }
}
