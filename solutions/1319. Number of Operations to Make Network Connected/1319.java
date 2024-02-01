class Solution {
  public int makeConnected(int n, int[][] connections) {
    // To connect n nodes, we need at least n - 1 edges
    if (connections.length < n - 1)
      return -1;

    int numOfConnected = 0;
    List<Integer>[] graph = new List[n];
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] connection : connections) {
      final int u = connection[0];
      final int v = connection[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = 0; i < n; ++i)
      if (seen.add(i)) {
        dfs(graph, i, seen);
        ++numOfConnected;
      }

    return numOfConnected - 1;
  }

  private void dfs(List<Integer>[] graph, int u, Set<Integer> seen) {
    for (final int v : graph[u])
      if (seen.add(v))
        dfs(graph, v, seen);
  }
}
