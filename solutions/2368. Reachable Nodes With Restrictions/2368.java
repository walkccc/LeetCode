class Solution {
  public int reachableNodes(int n, int[][] edges, int[] restricted) {
    List<Integer>[] tree = new List[n];
    boolean[] seen = new boolean[n];

    for (int i = 0; i < n; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    for (final int r : restricted)
      seen[r] = true;

    return dfs(tree, 0, seen);
  }

  private int dfs(List<Integer>[] tree, int u, boolean[] seen) {
    if (seen[u])
      return 0;

    seen[u] = true;
    int ans = 1;

    for (final int v : tree[u])
      ans += dfs(tree, v, seen);

    return ans;
  }
}
