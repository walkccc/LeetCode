enum State { INIT, VISITING, VISITED }

class Solution {
  public List<Integer> eventualSafeNodes(int[][] graph) {
    List<Integer> ans = new ArrayList<>();
    State[] state = new State[graph.length];

    for (int i = 0; i < graph.length; ++i)
      if (!hasCycle(graph, i, state))
        ans.add(i);

    return ans;
  }

  private boolean hasCycle(int[][] graph, int u, State[] state) {
    if (state[u] == State.VISITING)
      return true;
    if (state[u] == State.VISITED)
      return false;

    state[u] = State.VISITING;
    for (final int v : graph[u])
      if (hasCycle(graph, v, state))
        return true;
    state[u] = State.VISITED;

    return false;
  }
}
