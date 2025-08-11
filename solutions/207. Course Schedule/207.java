enum State { INIT, VISITING, VISITED }

class Solution {
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<Integer>[] graph = new List[numCourses];
    State[] states = new State[numCourses];

    for (int i = 0; i < numCourses; ++i)
      graph[i] = new ArrayList<>();

    for (int[] prerequisite : prerequisites) {
      final int u = prerequisite[1];
      final int v = prerequisite[0];
      graph[u].add(v);
    }

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, states))
        return false;

    return true;
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] states) {
    if (states[u] == State.VISITING)
      return true;
    if (states[u] == State.VISITED)
      return false;
    states[u] = State.VISITING;
    for (final int v : graph[u])
      if (hasCycle(graph, v, states))
        return true;
    states[u] = State.VISITED;
    return false;
  }
}
