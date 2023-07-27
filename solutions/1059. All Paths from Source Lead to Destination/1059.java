enum State { kInit, kVisiting, kVisited }

class Solution {
  public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
    List<Integer>[] graph = new List[n];
    State[] states = new State[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges)
      graph[e[0]].add(e[1]);

    return acyclic(graph, source, destination, states);
  }

  private boolean acyclic(List<Integer>[] graph, int u, int dest, State[] states) {
    if (graph[u].isEmpty())
      return u == dest;
    if (states[u] == State.kVisiting)
      return false;
    if (states[u] == State.kVisited)
      return true;

    states[u] = State.kVisiting;
    for (final int v : graph[u])
      if (!acyclic(graph, v, dest, states))
        return false;
    states[u] = State.kVisited;

    return true;
  }
}
