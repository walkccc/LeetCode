class Solution {
  public int minRunesToAdd(int n, int[] crystals, int[] flowFrom, int[] flowTo) {
    List<Integer>[] graph = new ArrayList[n];
    List<Integer>[] reversedGraph = new ArrayList[n];

    for (int i = 0; i < n; ++i) {
      graph[i] = new ArrayList<>();
      reversedGraph[i] = new ArrayList<>();
    }

    for (int i = 0; i < flowFrom.length; ++i) {
      final int u = flowFrom[i];
      final int v = flowTo[i];
      graph[u].add(v);
      reversedGraph[v].add(u);
    }

    // Identify Strongly Connected Components (SCC) using Kosaraju's Algorithm.
    boolean[] seen = new boolean[n];
    List<Integer> orderStack = new ArrayList<>();
    int[] componentIds = new int[n];
    int componentCount = 0;

    for (int i = 0; i < n; ++i)
      if (!seen[i])
        kosaraju(graph, i, seen, orderStack);

    Arrays.fill(componentIds, -1);

    for (int i = orderStack.size() - 1; i >= 0; --i) {
      final int u = orderStack.get(i);
      if (componentIds[u] == -1)
        identifySCC(reversedGraph, u, componentIds, componentCount++);
    }

    // Track crystal-containing components and inter-component edges.
    boolean[] hasCrystal = new boolean[componentCount];
    boolean[] hasInterComponentEdge = new boolean[componentCount];

    for (final int u : crystals)
      hasCrystal[componentIds[u]] = true;

    for (int i = 0; i < flowFrom.length; ++i) {
      final int id1 = componentIds[flowFrom[i]];
      final int id2 = componentIds[flowTo[i]];
      if (id1 != id2)
        hasInterComponentEdge[id2] = true;
    }

    // Count components requiring additional runes
    int ans = 0;

    for (int i = 0; i < componentCount; ++i)
      if (!hasCrystal[i] && !hasInterComponentEdge[i])
        ++ans;

    return ans;
  }

  // Creates a topological order stack using Kosaraju's Algorithm.
  private void kosaraju(List<Integer>[] graph, int u, boolean[] seen, List<Integer> orderStack) {
    seen[u] = true;
    for (final int v : graph[u])
      if (!seen[v])
        kosaraju(graph, v, seen, orderStack);
    orderStack.add(u);
  }

  // Assigns component IDs during SCC identification in the second DFS.
  private void identifySCC(List<Integer>[] reversedGraph, int u, int[] componentIds,
                           int componentId) {
    if (componentIds[u] != -1)
      return;
    componentIds[u] = componentId;
    for (final int v : reversedGraph[u])
      if (componentIds[v] == -1)
        identifySCC(reversedGraph, v, componentIds, componentId);
  }
}
