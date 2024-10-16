class Solution {
  public int collectTheCoins(int[] coins, int[][] edges) {
    final int n = coins.length;
    Set<Integer>[] tree = new Set[n];
    Deque<Integer> leavesToBeRemoved = new ArrayDeque<>();

    for (int i = 0; i < n; ++i)
      tree[i] = new HashSet<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    for (int i = 0; i < n; ++i) {
      int u = i;
      // Remove the leaves that don't have coins.
      while (tree[u].size() == 1 && coins[u] == 0) {
        final int v = tree[u].iterator().next();
        tree[u].clear();
        tree[v].remove(u);
        u = v; // Walk up to its parent.
      }
      // After trimming leaves without coins, leaves with coins may satisfy
      // `leavesToBeRemoved`.
      if (tree[u].size() == 1)
        leavesToBeRemoved.offer(u);
    }

    // Remove each remaining leaf node and its parent. The remaining nodes are
    // the ones that must be visited.
    for (int i = 0; i < 2; ++i)
      for (int sz = leavesToBeRemoved.size(); sz > 0; --sz) {
        final int u = leavesToBeRemoved.poll();
        if (!tree[u].isEmpty()) {
          final int v = tree[u].iterator().next();
          tree[u].clear();
          tree[v].remove(u);
          if (tree[v].size() == 1)
            leavesToBeRemoved.offer(v);
        }
      }

    return Arrays.stream(tree).mapToInt(children -> children.size()).sum();
  }
}
