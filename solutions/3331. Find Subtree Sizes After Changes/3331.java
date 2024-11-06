class Solution {
  public int[] findSubtreeSizes(int[] parent, String s) {
    final int n = parent.length;
    int[] ans = new int[n];
    int[] newParent = parent.clone();
    List<Integer>[] tree = new ArrayList[n];

    for (int i = 0; i < n; ++i)
      tree[i] = new ArrayList<>();

    for (int i = 1; i < n; ++i) {
      final int closest = findClosestAncestor(i, parent, s);
      if (closest != -1)
        newParent[i] = closest;
    }

    for (int i = 1; i < n; ++i)
      tree[newParent[i]].add(i);

    dfs(tree, 0, ans);
    return ans;
  }

  // Returns the closest ancestor of node `u` that has the same value as `u`.
  private int findClosestAncestor(int u, int[] parent, String s) {
    for (int curr = parent[u]; curr != -1; curr = parent[curr])
      if (s.charAt(curr) == s.charAt(u))
        return curr;
    return -1;
  }

  private int dfs(List<Integer>[] tree, int u, int[] ans) {
    int sz = 1;
    for (final int v : tree[u])
      sz += dfs(tree, v, ans);
    return ans[u] = sz;
  }
}
