class Solution {
  public long maximumScoreAfterOperations(int[][] edges, int[] values) {
    List<Integer>[] tree = new ArrayList[values.length];

    for (int i = 0; i < values.length; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    return Arrays.stream(values).sum() - dfs(tree, 0, /*prev=*/-1, values);
  }

  private long dfs(List<Integer>[] tree, int u, int prev, int[] values) {
    if (u > 0 && tree[u].size() == 1)
      return values[u];
    long childrenSum = 0;
    for (final int v : tree[u])
      if (v != prev)
        childrenSum += dfs(tree, v, u, values);
    return Math.min(childrenSum, 1L * values[u]);
  }
}
