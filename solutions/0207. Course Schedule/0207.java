class Solution {
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<Integer>[] graph = new List[numCourses];
    State[] state = new State[numCourses];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (final int[] p : prerequisites)
      graph[p[1]].add(p[0]);

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(i, graph, state))
        return false;

    return true;
  }

  private enum State {
    INIT, VISITING, VISITED
  }

  private boolean hasCycle(int i, List<Integer>[] graph, State[] state) {
    if (state[i] == State.VISITING)
      return true;
    if (state[i] == State.VISITED)
      return false;

    state[i] = State.VISITING;
    for (final int neighbor : graph[i])
      if (hasCycle(neighbor, graph, state))
        return true;
    state[i] = State.VISITED;

    return false;
  }
}