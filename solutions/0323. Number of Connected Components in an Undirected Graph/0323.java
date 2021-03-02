class Solution {
  public int countComponents(int n, int[][] edges) {
    int ans = 0;
    List<Integer>[] graph = new List[n];
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    for (int i = 0; i < n; ++i)
      if (!seen.contains(i)) {
        bfs(graph, i, seen);
        ++ans;
      }

    return ans;
  }

  private void bfs(List<Integer>[] graph, int node, Set<Integer> seen) {
    Queue<Integer> q = new LinkedList<>(Arrays.asList(node));
    seen.add(node);

    while (!q.isEmpty()) {
      final int curr = q.poll();
      for (final int child : graph[curr])
        if (!seen.contains(child)) {
          q.offer(child);
          seen.add(child);
        }
    }
  }
}
