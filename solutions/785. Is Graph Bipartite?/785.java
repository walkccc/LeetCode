enum Color { WHITE, RED, GREEN }

class Solution {
  public boolean isBipartite(int[][] graph) {
    Color[] colors = new Color[graph.length];
    Arrays.fill(colors, Color.WHITE);

    for (int i = 0; i < graph.length; ++i) {
      // This node has been colored, so do nothing.
      if (colors[i] != Color.WHITE)
        continue;
      // Always paint red for a white node.
      colors[i] = Color.RED;
      // BFS.
      Queue<Integer> q = new ArrayDeque<>(List.of(i));
      while (!q.isEmpty())
        for (int sz = q.size(); sz > 0; --sz) {
          final int u = q.poll();
          for (final int v : graph[u]) {
            if (colors[v] == colors[u])
              return false;
            if (colors[v] == Color.WHITE) {
              colors[v] = colors[u] == Color.RED ? Color.GREEN : Color.RED;
              q.offer(v);
            }
          }
        }
    }

    return true;
  }
}
