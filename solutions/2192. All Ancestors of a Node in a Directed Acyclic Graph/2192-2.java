class Solution {
  public List<List<Integer>> getAncestors(int n, int[][] edges) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer>[] graph = new List[n];
    TreeSet<Integer>[] ancestors = new TreeSet[n]; // {u: {ancestors}}
    int[] inDegrees = new int[n];

    for (int i = 0; i < n; ++i) {
      graph[i] = new ArrayList<>();
      ancestors[i] = new TreeSet<>();
    }

    // Build the graph.
    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    Queue<Integer> q = IntStream.range(0, n)
                           .filter(i -> inDegrees[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.poll();
        for (final int v : graph[u]) {
          ancestors[v].add(u);
          ancestors[v].addAll(ancestors[u]);
          if (--inDegrees[v] == 0)
            q.offer(v);
        }
      }
    }

    for (TreeSet<Integer> nodes : ancestors)
      ans.add(new ArrayList<>(nodes));

    return ans;
  }
}
