enum State { INIT, VISITING, VISITED }

class Solution {
  public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
    List<Integer>[] graph = new List[n];
    State[] state = new State[n];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges)
      graph[edge[0]].add(edge[1]);

    return acyclic(graph, source, destination, state);
  }

  private boolean acyclic(List<Integer>[] graph, int node, int dest, State[] state) {
    if (graph[node].isEmpty())
      return node == dest;
    if (state[node] == State.VISITING)
      return false;
    if (state[node] == State.VISITED)
      return true;

    state[node] = State.VISITING;
    for (final int child : graph[node])
      if (!acyclic(graph, child, dest, state))
        return false;
    state[node] = State.VISITED;

    return true;
  }
}
