enum State { INIT, VISITING, VISITED }

class Solution {
  public int minimumSemesters(int N, int[][] relations) {
    List<Integer>[] graph = new List[N + 1];
    State[] state = new State[N + 1];
    int[] depth = new int[N + 1];
    Arrays.fill(depth, 1);

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] r : relations)
      graph[r[0]].add(r[1]);

    for (int i = 1; i <= N; ++i)
      if (hasCycle(graph, i, state, depth))
        return -1;

    return Arrays.stream(depth).max().getAsInt();
  }

  private boolean hasCycle(List<Integer>[] graph, int node, State[] state, int[] depth) {
    if (state[node] == State.VISITING)
      return true;
    if (state[node] == State.VISITED)
      return false;

    state[node] = State.VISITING;
    for (final int child : graph[node]) {
      if (hasCycle(graph, child, state, depth))
        return true;
      depth[node] = Math.max(depth[node], 1 + depth[child]);
    }
    state[node] = State.VISITED;

    return false;
  }
}
