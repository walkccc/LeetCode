class Solution {
  public long maxOutput(int n, int[][] edges, int[] price) {
    List<Integer>[] tree = new List[n];
    // maxSums[i] := the maximum the sum of path rooted at i
    int[] maxSums = new int[n];

    for (int i = 0; i < n; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    // Precalculate `maxSums`.
    maxSum(tree, 0, /*prev=*/-1, maxSums, price);
    reroot(tree, 0, /*prev=*/-1, /*parentSum=*/0, maxSums, price);
    return (long) ans;
  }

  private int ans = 0;

  private int maxSum(List<Integer>[] tree, int u, int prev, int[] maxSums, int[] price) {
    int maxChildSum = 0;
    for (final int v : tree[u])
      if (prev != v)
        maxChildSum = Math.max(maxChildSum, maxSum(tree, v, u, maxSums, price));
    return maxSums[u] = price[u] + maxChildSum;
  }

  private void reroot(List<Integer>[] tree, int u, int prev, int parentSum, int[] maxSums,
                      int[] price) {
    // Get top two sums and top one node index.
    int maxSubtreeSum1 = 0;
    int maxSubtreeSum2 = 0;
    int maxNode = -1;
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      if (maxSums[v] > maxSubtreeSum1) {
        maxSubtreeSum2 = maxSubtreeSum1;
        maxSubtreeSum1 = maxSums[v];
        maxNode = v;
      } else if (maxSums[v] > maxSubtreeSum2) {
        maxSubtreeSum2 = maxSums[v];
      }
    }

    if (tree[u].size() == 1)
      ans = Math.max(ans, Math.max(parentSum, maxSubtreeSum1));

    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      final int nextParentSum = (v == maxNode ? price[u] + Math.max(parentSum, maxSubtreeSum2)
                                              : price[u] + Math.max(parentSum, maxSubtreeSum1));
      reroot(tree, v, u, nextParentSum, maxSums, price);
    }
  }
}
