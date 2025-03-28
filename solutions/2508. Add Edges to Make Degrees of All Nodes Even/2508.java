class Solution {
  public boolean isPossible(int n, List<List<Integer>> edges) {
    Set<Integer>[] graph = new Set[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new HashSet<>();

    for (List<Integer> edge : edges) {
      final int u = edge.get(0) - 1;
      final int v = edge.get(1) - 1;
      graph[u].add(v);
      graph[v].add(u);
    }

    List<Integer> oddNodes = getOddNodes(graph);
    if (oddNodes.isEmpty())
      return true;
    if (oddNodes.size() == 2) {
      final int a = oddNodes.get(0);
      final int b = oddNodes.get(1);
      for (int i = 0; i < n; ++i)
        // Can connect i with a and i with b.
        if (!graph[i].contains(a) && !graph[i].contains(b))
          return true;
    }
    if (oddNodes.size() == 4) {
      final int a = oddNodes.get(0);
      final int b = oddNodes.get(1);
      final int c = oddNodes.get(2);
      final int d = oddNodes.get(3);
      return (!graph[a].contains(b) && !graph[c].contains(d)) ||
          (!graph[a].contains(c) && !graph[b].contains(d)) ||
          (!graph[a].contains(d) && !graph[b].contains(c));
    }
    return false;
  }

  private List<Integer> getOddNodes(Set<Integer>[] graph) {
    List<Integer> oddNodes = new ArrayList<>();
    for (int i = 0; i < graph.length; ++i)
      if (graph[i].size() % 2 == 1)
        oddNodes.add(i);
    return oddNodes;
  }
}
