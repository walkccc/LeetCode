enum State { INIT, VISITING, VISITED }

class Solution {
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<Integer>[] graph = new List[numCourses];
    State[] state = new State[numCourses];

    for (int i = 0; i < numCourses; ++i)
      graph[i] = new ArrayList<>();

    for (int[] p : prerequisites)
      graph[p[1]].add(p[0]);

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state))
        return false;

    return true;
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] state) {
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
