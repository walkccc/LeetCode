class Solution {
  public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
    final int diameter1 = getDiameter(edges1);
    final int diameter2 = getDiameter(edges2);
    final int combinedDiameter = (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1;
    return Math.max(Math.max(diameter1, diameter2), combinedDiameter);
  }

  private int getDiameter(int[][] edges) {
    final int n = edges.length + 1;
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    int[] maxDiameter = new int[1];
    maxDepth(graph, 0, -1, maxDiameter);
    return maxDiameter[0];
  }

  // Similar to 1522. Diameter of N-Ary Tree
  // Returns the maximum depth of the subtree rooted at u.
  private int maxDepth(List<Integer>[] graph, int u, int prev, int[] maxDiameter) {
    int maxSubDepth1 = 0;
    int maxSubDepth2 = 0;
    for (final int v : graph[u]) {
      if (v == prev)
        continue;
      final int maxSubDepth = maxDepth(graph, v, u, maxDiameter);
      if (maxSubDepth > maxSubDepth1) {
        maxSubDepth2 = maxSubDepth1;
        maxSubDepth1 = maxSubDepth;
      } else if (maxSubDepth > maxSubDepth2) {
        maxSubDepth2 = maxSubDepth;
      }
    }
    maxDiameter[0] = Math.max(maxDiameter[0], maxSubDepth1 + maxSubDepth2);
    return 1 + maxSubDepth1;
  }
}
