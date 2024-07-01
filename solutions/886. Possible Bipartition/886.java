enum Color { kWhite, kRed, kGreen }

class Solution {
  public boolean possibleBipartition(int n, int[][] dislikes) {
    List<Integer>[] graph = new List[n + 1];
    Color[] colors = new Color[n + 1];
    Arrays.fill(colors, Color.kWhite);

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] d : dislikes) {
      final int u = d[0];
      final int v = d[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    // Reduce to 785. Is Graph Bipartite?
    for (int i = 1; i <= n; ++i)
      if (colors[i] == Color.kWhite && !isValidColor(graph, i, colors, Color.kRed))
        return false;

    return true;
  }

  private boolean isValidColor(List<Integer>[] graph, int u, Color[] colors, Color color) {
    // Always paint red for a white node.
    if (colors[u] != Color.kWhite)
      return colors[u] == color;

    colors[u] = color; // Always paint the node with `color`.

    // All the children should have valid colors.
    for (final int v : graph[u])
      if (!isValidColor(graph, v, colors, color == Color.kRed ? Color.kGreen : Color.kRed))
        return false;

    return true;
  }
}
