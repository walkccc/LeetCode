class Solution {
  public int[] sumOfDistancesInTree(int n, int[][] edges) {
    int[] ans = new int[n];
    int[] count = new int[n];
    Set<Integer>[] tree = new Set[n];

    Arrays.fill(count, 1);

    for (int i = 0; i < n; ++i)
      tree[i] = new HashSet<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    postorder(tree, 0, -1, count, ans);
    preorder(tree, 0, -1, count, ans);
    return ans;
  }

  private void postorder(Set<Integer>[] tree, int u, int prev, int[] count, int[] ans) {
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      postorder(tree, v, u, count, ans);
      count[u] += count[v];
      ans[u] += ans[v] + count[v];
    }
  }

  private void preorder(Set<Integer>[] tree, int u, int prev, int[] count, int[] ans) {
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      // count[v] us are 1 step closer from v than prev.
      // (n - count[v]) us are 1 step farther from v than prev.
      ans[v] = ans[u] - count[v] + (tree.length - count[v]);
      preorder(tree, v, u, count, ans);
    }
  }
}
