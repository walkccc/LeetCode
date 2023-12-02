class Solution {
  public int maximumPoints(int[][] edges, int[] coins, int k) {
    final int n = coins.length;
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    dp = new Integer[n][kMaxHalved + 1];

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    return dfs(graph, 0, /*prev=*/-1, coins, k, /*halved=*/0);
  }

  private static final int kMaxCoint = 10000;
  private static final int kMaxHalved = (int) (Math.log(kMaxCoint) / Math.log(2)) + 1;
  private Integer[][] dp;

  private int dfs(List<Integer>[] graph, int u, int prev, int[] coins, int k, int halved) {
    // All the children will be 0, so no need to explore.
    if (halved > kMaxHalved)
      return 0;
    if (dp[u][halved] != null)
      return dp[u][halved];

    final int val = coins[u] / (1 << halved);
    int takeAll = val - k;
    int takeHalf = (int) Math.floor(val / 2.0);

    for (final int v : graph[u]) {
      if (v == prev)
        continue;
      takeAll += dfs(graph, v, u, coins, k, halved);
      takeHalf += dfs(graph, v, u, coins, k, halved + 1);
    }

    return dp[u][halved] = Math.max(takeAll, takeHalf);
  }
}
