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

  private boolean hasCycle(int[][] graph, int node, State[] state) {
    if (state[node] == State.VISITING)
      return true;
    if (state[node] == State.VISITED)
      return false;

    state[node] = State.VISITING;
    for (final int child : graph[node])
      if (hasCycle(graph, child, state))
        return true;
    state[node] = State.VISITED;

    return false;
  }
}
