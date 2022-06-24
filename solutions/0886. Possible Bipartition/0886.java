enum Color { WHITE, RED, GREEN }

class Solution {
  public boolean possibleBipartition(int n, int[][] dislikes) {
    List<Integer>[] graph = new List[n + 1];
    Color[] colors = new Color[n + 1];
    Arrays.fill(colors, Color.WHITE);

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] d : dislikes) {
      final int u = d[0];
      final int v = d[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    // reduce to 785. Is Graph Bipartite?
    for (int i = 1; i <= n; ++i)
      if (colors[i] == Color.WHITE && !isValidColor(graph, i, colors, Color.RED))
        return false;

    return true;
  }

  private boolean isValidColor(List<Integer>[] graph, int u, Color[] colors, Color color) {
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
