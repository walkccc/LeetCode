enum Color { kWhite, kRed, kGreen }

class Solution {
  public boolean isBipartite(int[][] graph) {
    Color[] colors = new Color[graph.length];
    Arrays.fill(colors, Color.kWhite);

    for (int i = 0; i < graph.length; ++i)
      if (colors[i] == Color.kWhite && !isValidColor(graph, i, colors, Color.kRed))
        return false;

    return true;
  }

  private boolean isValidColor(int[][] graph, int u, Color[] colors, Color color) {
    // The painted color should be same as the `color`.
    if (colors[u] != Color.kWhite)
      return colors[u] == color;

    colors[u] = color;

    // All the children should have valid colors.
    for (final int v : graph[u])
      if (!isValidColor(graph, v, colors, color == Color.kRed ? Color.kGreen : Color.kRed))
        return false;

    return true;
  }
}
