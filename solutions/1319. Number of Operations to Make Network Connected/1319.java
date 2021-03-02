class Solution {
  public int makeConnected(int n, int[][] connections) {
    // to connect n nodes, we need at least n - 1 edges
    if (connections.length < n - 1)
      return -1;

    int numOfConnected = 0;
    List<Integer>[] graph = new List[n];
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] conn : connections) {
      graph[conn[0]].add(conn[1]);
      graph[conn[1]].add(conn[0]);
    }

    for (int i = 0; i < n; ++i)
      if (seen.add(i)) {
        dfs(graph, i, seen);
        ++numOfConnected;
      }

    return numOfConnected - 1;
  }

  private void dfs(List<Integer>[] graph, int node, Set<Integer> seen) {
    for (final int child : graph[node])
      if (seen.add(child))
        dfs(graph, child, seen);
  }
}
