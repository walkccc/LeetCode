class Solution {
  public int treeDiameter(int[][] edges) {
    final int n = edges.length;
    List<Integer>[] tree = new List[n + 1];

    for (int i = 0; i < tree.length; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    maxDepth(tree, 0, -1);
    return ans;
  }

  private int ans = 0;

  private int maxDepth(List<Integer>[] tree, int u, int parent) {
    int maxDepth1 = 0;  // the maximum depth
    int maxDepth2 = -1; // the second maximum depth

    for (final int v : tree[u]) {
      if (v == parent)
        continue;
      final int depth = maxDepth(tree, v, u);
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
