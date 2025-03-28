class Solution {
  public int countGoodNodes(int[][] edges) {
    final int n = edges.length + 1;
    List<Integer>[] graph = new ArrayList<>(n);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(graph, 0, -1);
    return ans;
  }

  private int ans = 0;

  // Returns the size of the subtree rooted at u.
  private int dfs(List<Integer>[] graph, int u, int prev) {
    int size = 1;
    List<Integer> childrenSizes = new ArrayList<>();

    for (final int v : graph[u]) {
      if (v == prev)
        continue;
      final int childSize = dfs(graph, v, u);
      size += childSize;
      childrenSizes.add(childSize);
    }

    if (childrenSizes.isEmpty() || allSameSizes(childrenSizes))
      ++ans;

    return size;
  }

  private boolean allSameSizes(List<Integer> childrenSizes) {
    for (int i = 1; i < childrenSizes.size(); ++i)
      if (!childrenSizes.get(i).equals(childrenSizes.get(0)))
        return false;
    return true;
  }
}
