enum State { kInit, kVisiting, kVisited }

class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    Deque<Integer> ans = new ArrayDeque<>();
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
      if (hasCycle(graph, i, states, ans))
        return new int[] {};

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] states, Deque<Integer> ans) {
    if (states[u] == State.kVisiting)
      return true;
    if (states[u] == State.kVisited)
      return false;

    states[u] = State.kVisiting;
    for (final int v : graph[u])
      if (hasCycle(graph, v, states, ans))
        return true;
    states[u] = State.kVisited;
    ans.addFirst(u);

    return false;
  }
}
