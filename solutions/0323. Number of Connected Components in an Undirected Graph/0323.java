class Solution {
  public int countComponents(int n, int[][] edges) {
    int ans = 0;
    List<Integer>[] graph = new List[n];
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = 0; i < n; ++i)
      if (!seen.contains(i)) {
        bfs(graph, i, seen);
        ++ans;
      }

    return ans;
  }

  private void bfs(List<Integer>[] graph, int node, Set<Integer> seen) {
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(node));
    seen.add(node);

    while (!q.isEmpty()) {
      final int u = q.poll();
      for (final int v : graph[u])
        if (!seen.contains(v)) {
          q.offer(v);
          seen.add(v);
        }
    }
  }
}
