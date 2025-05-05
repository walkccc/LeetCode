enum State { INIT, VISITING, VISITED }

class Solution {
  public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
    List<Integer>[] graph = new List[n];
    State[] states = new State[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
    }

    return acyclic(graph, source, destination, states);
  }

  private boolean acyclic(List<Integer>[] graph, int u, int dest, State[] states) {
    if (graph[u].isEmpty())
      return u == dest;
    if (states[u] == State.VISITING)
      return false;
    if (states[u] == State.VISITED)
      return true;

    states[u] = State.VISITING;
    for (final int v : graph[u])
      if (!acyclic(graph, v, dest, states))
        return false;
    states[u] = State.VISITED;

    return true;
  }
}
