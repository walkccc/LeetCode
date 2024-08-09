class Solution {
  public int maximumSubtreeSize(int[][] edges, int[] colors) {
    List<Integer>[] tree = new ArrayList[colors.length];

    for (int i = 0; i < colors.length; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
    }

    dfs(tree, 0, colors);
    return ans;
  }

  private int ans = 1;

  // Returns the size of subtree of u if every node in the subtree has the same
  // color. Otherwise, returns -1.
  private int dfs(List<Integer>[] tree, int u, int[] colors) {
    int res = 1;
    for (int v : tree[u]) {
      if (colors[v] != colors[u])
        res = -1;
      // If any node in the subtree of v has a different color, the result of
      // the subtree of u will be -1 as well.
      int subtreeSize = dfs(tree, v, colors);
      if (subtreeSize == -1)
        res = -1;
      else if (res != -1)
        res += subtreeSize;
    }
    ans = Math.max(ans, res);
    return res;
  }
}
