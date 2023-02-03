enum State { kInit, kVisiting, kVisited }

class Solution {
  public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
    List<Integer>[] graph = new List[n];
    State[] state = new State[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges)
      graph[e[0]].add(e[1]);

    return acyclic(graph, source, destination, state);
  }

  private boolean acyclic(List<Integer>[] graph, int u, int dest, State[] state) {
    if (graph[u].isEmpty())
      return u == dest;
    if (state[u] == State.kVisiting)
      return false;
    if (state[u] == State.kVisited)
      return true;

    state[u] = State.kVisiting;
    for (final int v : graph[u])
      if (!acyclic(graph, v, dest, state))
        return false;
    state[u] = State.kVisited;

    return true;
  }
}
