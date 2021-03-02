enum State { INIT, VISITING, VISITED }

class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    Deque<Integer> ans = new ArrayDeque<>();
    List<Integer>[] graph = new List[numCourses];
    State[] state = new State[numCourses];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] p : prerequisites)
      graph[p[1]].add(p[0]);

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state, ans))
        return new int[] {};

    return ans.stream().mapToInt(i -> i).toArray();
  }

  private boolean hasCycle(List<Integer>[] graph, int node, State[] state, Deque<Integer> ans) {
    if (state[node] == State.VISITING)
      return true;
    if (state[node] == State.VISITED)
      return false;

    state[node] = State.VISITING;
    for (final int child : graph[node])
      if (hasCycle(graph, child, state, ans))
        return true;
    state[node] = State.VISITED;
    ans.addFirst(node);

    return false;
  }
}
