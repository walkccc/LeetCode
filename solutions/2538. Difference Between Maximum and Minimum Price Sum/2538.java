class Solution {
  public long maxOutput(int n, int[][] edges, int[] price) {
    List<Integer>[] graph = new List[n];
    int[] maxSums = new int[n]; // maxSums[i] := max sum of path rooted at i.

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    // Precalculate `maxSums`.
    maxSum(graph, 0, /*prev=*/-1, maxSums, price);
    reroot(graph, 0, /*prev=*/-1, /*parentSum=*/0, maxSums, price);
    return (long) ans;
  }

  private int ans = 0;

  private int maxSum(List<Integer>[] graph, int u, int prev, int[] maxSums, int[] price) {
    int maxChildSum = 0;
    for (final int v : graph[u])
      if (prev != v)
        maxChildSum = Math.max(maxChildSum, maxSum(graph, v, u, maxSums, price));
    return maxSums[u] = price[u] + maxChildSum;
  }

  private void reroot(List<Integer>[] graph, int u, int prev, int parentSum, int[] maxSums,
                      int[] price) {
    // Get top two sums and top one node index.
    int maxSubtreeSum1 = 0;
    int maxSubtreeSum2 = 0;
    int maxNode = -1;
    for (final int v : graph[u]) {
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

    if (graph[u].size() == 1)
      ans = Math.max(ans, Math.max(parentSum, maxSubtreeSum1));

    for (final int v : graph[u]) {
      if (v == prev)
        continue;
      final int nextParentSum = (v == maxNode ? price[u] + Math.max(parentSum, maxSubtreeSum2)
                                              : price[u] + Math.max(parentSum, maxSubtreeSum1));
      reroot(graph, v, u, nextParentSum, maxSums, price);
    }
  }
}
