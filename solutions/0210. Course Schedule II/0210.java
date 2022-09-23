enum State { INIT, VISITING, VISITED }

class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    Deque<Integer> ans = new ArrayDeque<>();
    List<Integer>[] graph = new List[numCourses];
    State[] state = new State[numCourses];

    for (int i = 0; i < numCourses; ++i)
      graph[i] = new ArrayList<>();

    for (int[] p : prerequisites)
      graph[p[1]].add(p[0]);

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state, ans))
        return new int[] {};

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] state, Deque<Integer> ans) {
    if (state[u] == State.VISITING)
      return true;
    if (state[u] == State.VISITED)
      return false;

    state[u] = State.VISITING;
    for (final int v : graph[u])
      if (hasCycle(graph, v, state, ans))
        return true;
    state[u] = State.VISITED;
    ans.addFirst(u);

    return false;
  }
}
