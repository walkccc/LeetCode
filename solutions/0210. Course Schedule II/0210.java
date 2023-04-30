enum State { kInit, kVisiting, kVisited }

class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    Deque<Integer> ans = new ArrayDeque<>();
    List<Integer>[] graph = new List[numCourses];
    State[] state = new State[numCourses];

    for (int i = 0; i < numCourses; ++i)
      graph[i] = new ArrayList<>();

    for (int[] prerequisite : prerequisites) {
      final int u = prerequisite[1];
      final int v = prerequisite[0];
      graph[u].add(v);
    }

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state, ans))
        return new int[] {};

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] state, Deque<Integer> ans) {
    if (state[u] == State.kVisiting)
      return true;
    if (state[u] == State.kVisited)
      return false;

    state[u] = State.kVisiting;
    for (final int v : graph[u])
      if (hasCycle(graph, v, state, ans))
        return true;
    state[u] = State.kVisited;
    ans.addFirst(u);

    return false;
  }
}
