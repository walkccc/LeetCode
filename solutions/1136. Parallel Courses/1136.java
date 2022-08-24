enum State { INIT, VISITING, VISITED }

class Solution {
  public int minimumSemesters(int n, int[][] relations) {
    List<Integer>[] graph = new List[n];
    State[] state = new State[n];
    int[] depth = new int[n];
    Arrays.fill(depth, 1);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] r : relations)
      graph[r[0] - 1].add(r[1] - 1);

    for (int i = 0; i < n; ++i)
      if (hasCycle(graph, i, state, depth))
        return -1;

    return Arrays.stream(depth).max().getAsInt();
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] state, int[] depth) {
    if (state[u] == State.VISITING)
      return true;
    if (state[u] == State.VISITED)
      return false;

    state[u] = State.VISITING;
    for (final int v : graph[u]) {
      if (hasCycle(graph, v, state, depth))
        return true;
      depth[u] = Math.max(depth[u], 1 + depth[v]);
    }
    state[u] = State.VISITED;

    return false;
  }
}
