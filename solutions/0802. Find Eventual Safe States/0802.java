enum State { kInit, kVisiting, kVisited }

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
    if (state[u] == State.kVisiting)
      return true;
    if (state[u] == State.kVisited)
      return false;

    state[u] = State.kVisiting;
    for (final int v : graph[u])
      if (hasCycle(graph, v, state))
        return true;
    state[u] = State.kVisited;

    return false;
  }
}
