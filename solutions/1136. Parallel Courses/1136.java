enum State { INIT, VISITING, VISITED }

class Solution {
  public int minimumSemesters(int n, int[][] relations) {
    List<Integer>[] graph = new List[n];
    State[] states = new State[n];
    int[] depth = new int[n];
    Arrays.fill(depth, 1);
    Arrays.setAll(graph, i -> new ArrayList<>());

    for (int[] relation : relations) {
      final int u = relation[0] - 1;
      final int v = relation[1] - 1;
      graph[u].add(v);
    }

    for (int i = 0; i < n; ++i)
      if (hasCycle(graph, i, states, depth))
        return -1;

    return Arrays.stream(depth).max().getAsInt();
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] states, int[] depth) {
    if (states[u] == State.VISITING)
      return true;
    if (states[u] == State.VISITED)
      return false;
    states[u] = State.VISITING;
    for (final int v : graph[u]) {
      if (hasCycle(graph, v, states, depth))
        return true;
      depth[u] = Math.max(depth[u], 1 + depth[v]);
    }
    states[u] = State.VISITED;
    return false;
  }
}
