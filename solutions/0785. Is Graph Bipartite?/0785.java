enum Color { WHITE, RED, GREEN }

class Solution {
  public boolean isBipartite(int[][] graph) {
    Color[] colors = new Color[graph.length];
    Arrays.fill(colors, Color.WHITE);

    for (int i = 0; i < graph.length; ++i) {
      // if it's colored already, then we do nothing
      if (colors[i] != Color.WHITE)
        continue;
      // colors[i] is Color.WHITE
      colors[i] = Color.RED; // always color Color.RED
      // start doing BFS
      Queue<Integer> q = new LinkedList<>(Arrays.asList(i));
      while (!q.isEmpty()) {
        for (int size = q.size(); size > 0; --size) {
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
    }

    return true;
  }
}
