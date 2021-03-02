class Solution {
  public int treeDiameter(int[][] edges) {
    final int n = edges.length;

    List<Integer>[] graph = new List[n + 1];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    maxDepth(graph, 0, -1);

    return ans;
  }

  private int ans = 0;

  private int maxDepth(List<Integer>[] graph, int node, int parent) {
    int maxDepth1 = 0; // the max depth
    int maxDepth2 = -1; // the 2nd max depth

    for (final int child : graph[node]) {
      if (child == parent)
        continue;
      final int depth = maxDepth(graph, child, node);
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
