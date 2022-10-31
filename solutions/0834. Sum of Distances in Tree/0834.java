class Solution {
  public int[] sumOfDistancesInTree(int N, int[][] edges) {
    int[] ans = new int[N];
    int[] count = new int[N];
    Set<Integer>[] tree = new Set[N];

    Arrays.fill(count, 1);

    for (int i = 0; i < N; ++i)
      tree[i] = new HashSet<>();

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    postorder(tree, 0, -1, count, ans);
    preorder(tree, 0, -1, count, ans);
    return ans;
  }

  private void postorder(Set<Integer>[] tree, int node, int parent, int[] count, int[] ans) {
    for (final int child : tree[node]) {
      if (child == parent)
        continue;
      postorder(tree, child, node, count, ans);
      count[node] += count[child];
      ans[node] += ans[child] + count[child];
    }
  }

  private void preorder(Set<Integer>[] tree, int node, int parent, int[] count, int[] ans) {
    for (final int child : tree[node]) {
      if (child == parent)
        continue;
      // count[child] nodes are 1 step closer from child than parent
      // (N - count[child]) nodes are 1 step farther from child than parent
      ans[child] = ans[node] - count[child] + (tree.length - count[child]);
      preorder(tree, child, node, count, ans);
    }
  }
}
