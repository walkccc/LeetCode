class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    List<Integer> ans = new ArrayList<>();
    List<Integer>[] graph = new List[numCourses];
    int[] inDegrees = new int[numCourses];

    for (int i = 0; i < numCourses; ++i)
      graph[i] = new ArrayList<>();

    // Build the graph.
    for (int[] prerequisite : prerequisites) {
      final int u = prerequisite[1];
      final int v = prerequisite[0];
      graph[u].add(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    Queue<Integer> q = IntStream.range(0, numCourses)
                           .filter(i -> inDegrees[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      final int u = q.poll();
      ans.add(u);
      for (final int v : graph[u])
        if (--inDegrees[v] == 0)
          q.offer(v);
    }

    if (ans.size() == numCourses)
      return ans.stream().mapToInt(Integer::intValue).toArray();
    return new int[] {};
  }
}
