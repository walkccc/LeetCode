class Solution {
  public int largestPathValue(String colors, int[][] edges) {
    final int n = colors.length();
    int ans = 0;
    int processed = 0;
    List<Integer>[] graph = new List[n];
    int[] inDegrees = new int[n];
    int[][] count = new int[n][26];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

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
      final int out = q.poll();
      ++processed;
      ans = Math.max(ans, ++count[out][colors.charAt(out) - 'a']);
      for (final int in : graph[out]) {
        for (int i = 0; i < 26; ++i)
          count[in][i] = Math.max(count[in][i], count[out][i]);
        if (--inDegrees[in] == 0)
          q.offer(in);
      }
    }

    return processed == n ? ans : -1;
  }
}
