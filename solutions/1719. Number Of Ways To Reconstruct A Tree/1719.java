class Solution {
  public int checkWays(int[][] pairs) {
    final int kMax = 501;
    Map<Integer, List<Integer>> graph = new HashMap<>();
    int[] degrees = new int[kMax];
    boolean[][] connected = new boolean[kMax][kMax];

    for (int[] pair : pairs) {
      final int u = pair[0];
      final int v = pair[1];
      graph.putIfAbsent(u, new ArrayList<>());
      graph.putIfAbsent(v, new ArrayList<>());
      graph.get(u).add(v);
      graph.get(v).add(u);
      ++degrees[u];
      ++degrees[v];
      connected[u][v] = true;
      connected[v][u] = true;
    }

    // For each node, sort its children by degrees in descending order.
    for (final int u : graph.keySet())
      graph.get(u).sort((a, b) -> Integer.compare(degrees[b], degrees[a]));

    final int root = getRoot(degrees, graph.keySet().size());
    if (root == -1)
      return 0;
    if (!dfs(graph, root, degrees, connected, new ArrayList<>(), new boolean[kMax]))
      return 0;
    return hasMoreThanOneWay ? 2 : 1;
  }

  private boolean hasMoreThanOneWay = false;

  // Returns the root by finding the node with a degree that equals to n - 1.
  private int getRoot(int[] degrees, int n) {
    for (int i = 1; i < degrees.length; ++i)
      if (degrees[i] == n - 1)
        return i;
    return -1;
  }

  // Returns true if each node rooted at u is connected to all of its ancestors.
  private boolean dfs(Map<Integer, List<Integer>> graph, int u, int[] degrees,
                      boolean[][] connected, List<Integer> ancestors, boolean[] seen) {
    seen[u] = true;

    for (final int ancestor : ancestors)
      if (!connected[u][ancestor])
        return false;

    ancestors.add(u);

    for (final int v : graph.get(u)) {
      if (seen[v])
        continue;
      // We can swap u with v, so there are more than one way.
      if (degrees[v] == degrees[u])
        hasMoreThanOneWay = true;
      if (!dfs(graph, v, degrees, connected, ancestors, seen))
        return false;
    }

    ancestors.remove(ancestors.size() - 1);
    return true;
  }
}
