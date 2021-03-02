class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    List<Integer>[] graph = new List[numCourses];
    int[] inDegree = new int[numCourses];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (int[] p : prerequisites) {
      final int out = p[1];
      final int in = p[0];
      graph[out].add(in);
      ++inDegree[in];
    }

    // topology
    List<Integer> ans = new ArrayList<>();
    Queue<Integer> q = new LinkedList<>();

    for (int i = 0; i < numCourses; ++i)
      if (inDegree[i] == 0)
        q.offer(i);

    while (!q.isEmpty()) {
      final int out = q.poll();
      ans.add(out);
      for (final int in : graph[out])
        if (--inDegree[in] == 0)
          q.offer(in);
    }

    if (ans.size() == numCourses)
      return ans.stream().mapToInt(i -> i).toArray();
    return new int[] {};
  }
}
