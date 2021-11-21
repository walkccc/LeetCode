class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    List<Integer> ans = new ArrayList<>();
    List<Integer>[] graph = new List[numCourses];
    int[] inDegree = new int[numCourses];
    Queue<Integer> q = new LinkedList<>();

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (int[] p : prerequisites) {
      final int u = p[1];
      final int v = p[0];
      graph[u].add(v);
      ++inDegree[v];
    }

    // topology
    for (int i = 0; i < numCourses; ++i)
      if (inDegree[i] == 0)
        q.offer(i);

    while (!q.isEmpty()) {
      final int u = q.poll();
      ans.add(u);
      for (final int v : graph[u])
        if (--inDegree[v] == 0)
          q.offer(v);
    }

    if (ans.size() == numCourses)
      return ans.stream().mapToInt(i -> i).toArray();
    return new int[] {};
  }
}
