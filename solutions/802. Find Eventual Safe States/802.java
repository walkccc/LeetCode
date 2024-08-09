enum State { kInit, kVisiting, kVisited }

class Solution {
  public List<Integer> eventualSafeNodes(int[][] graph) {
    List<Integer> ans = new ArrayList<>();
    State[] states = new State[graph.length];

    for (int i = 0; i < graph.length; ++i)
      if (!hasCycle(graph, i, states))
        ans.add(i);

    return ans;
  }

  private boolean hasCycle(int[][] graph, int u, State[] states) {
    if (states[u] == State.kVisiting)
      return true;
    if (states[u] == State.kVisited)
      return false;

    states[u] = State.kVisiting;
    for (final int v : graph[u])
      if (hasCycle(graph, v, states))
        return true;
    states[u] = State.kVisited;

    return false;
  }
}
