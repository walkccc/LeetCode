enum State { INIT, VISITING, VISITED }

class Solution {
  public boolean isPrintable(int[][] targetGrid) {
    final int MAX_COLOR = 60;
    final int m = targetGrid.length;
    final int n = targetGrid[0].length;
    // graph[u] := {v1, v2} means v1 and v2 cover u
    Set<Integer>[] graph = new HashSet[MAX_COLOR + 1];

    for (int color = 1; color <= MAX_COLOR; ++color) {
      // Get the rectangle of the current color.
      int minI = m;
      int minJ = n;
      int maxI = -1;
      int maxJ = -1;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (targetGrid[i][j] == color) {
            minI = Math.min(minI, i);
            minJ = Math.min(minJ, j);
            maxI = Math.max(maxI, i);
            maxJ = Math.max(maxJ, j);
          }
      // Add any color covering the current as the children.
      graph[color] = new HashSet<>();
      for (int i = minI; i <= maxI; ++i)
        for (int j = minJ; j <= maxJ; ++j)
          if (targetGrid[i][j] != color) {
            graph[color].add(targetGrid[i][j]);
          }
    }

    State[] states = new State[MAX_COLOR + 1];

    for (int color = 1; color <= MAX_COLOR; ++color)
      if (hasCycle(graph, color, states))
        return false;

    return true;
  }

  private boolean hasCycle(Set<Integer>[] graph, int u, State[] states) {
    if (states[u] == State.VISITING)
      return true;
    if (states[u] == State.VISITED)
      return false;
    states[u] = State.VISITING;
    for (int v : graph[u])
      if (hasCycle(graph, v, states))
        return true;
    states[u] = State.VISITED;
    return false;
  }
}
