class Solution {
  public int treeDiameter(int[][] edges) {
    final int n = edges.length;
    List<Integer>[] graph = new List[n + 1];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    maxDepth(graph, 0, -1);
    return ans;
  }

  private int ans = 0;

  private int maxDepth(List<Integer>[] graph, int u, int parent) {
    int maxDepth1 = 0;  // the max depth
    int maxDepth2 = -1; // the 2nd max depth

    for (final int v : graph[u]) {
      if (v == parent)
        continue;
      final int depth = maxDepth(graph, v, u);
      if (depth > maxDepth1) {
        maxDepth2 = maxDepth1;
        maxDepth1 = depth;
      } else if (depth > maxDepth2) {
        maxDepth2 = depth;
      }
    }

    ans = Math.max(ans, maxDepth1 + maxDepth2);
    return 1 + maxDepth1;
  }
}
