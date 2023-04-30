enum State { kInit, kVisiting, kVisited }

class Solution {
  public int minimumSemesters(int n, int[][] relations) {
    List<Integer>[] graph = new List[n];
    State[] state = new State[n];
    int[] depth = new int[n];
    Arrays.fill(depth, 1);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] relation : relations) {
      final int u = relation[0] - 1;
      final int v = relation[1] - 1;
      graph[u].add(v);
    }

    for (int i = 0; i < n; ++i)
      if (hasCycle(graph, i, state, depth))
        return -1;

    return Arrays.stream(depth).max().getAsInt();
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] state, int[] depth) {
    if (state[u] == State.kVisiting)
      return true;
    if (state[u] == State.kVisited)
      return false;

    state[u] = State.kVisiting;
    for (final int v : graph[u]) {
      if (hasCycle(graph, v, state, depth))
        return true;
      depth[u] = Math.max(depth[u], 1 + depth[v]);
    }
    state[u] = State.kVisited;

    return false;
  }
}
