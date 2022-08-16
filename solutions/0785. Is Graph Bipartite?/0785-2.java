enum Color { WHITE, RED, GREEN }

class Solution {
  public boolean isBipartite(int[][] graph) {
    Color[] colors = new Color[graph.length];
    Arrays.fill(colors, Color.WHITE);

    for (int i = 0; i < graph.length; ++i)
      if (colors[i] == Color.WHITE && !isValidColor(graph, i, colors, Color.RED))
        return false;

    return true;
  }

  private boolean isValidColor(int[][] graph, int u, Color[] colors, Color color) {
    // the painted color should be same as the `color`
    if (colors[u] != Color.WHITE)
      return colors[u] == color;

    colors[u] = color; // always paint w/ `color`

    // all children should have valid colors
    for (final int v : graph[u])
      if (!isValidColor(graph, v, colors, color == Color.RED ? Color.GREEN : Color.RED))
        return false;

    return true;
  }
}
