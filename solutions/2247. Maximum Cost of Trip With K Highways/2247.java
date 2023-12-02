class Solution {
  public int maximumCost(int n, int[][] highways, int k) {
    if (k + 1 > n)
      return -1;

    int ans = -1;
    // dp[u][mask] := the maximum cost of trip starting from u, where `mask` representing
    // visited cities
    dp = new Integer[n][1 << n];
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] h : highways) {
      final int u = h[0];
      final int v = h[1];
      final int w = h[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    for (int i = 0; i < n; ++i)
      ans = Math.max(ans, maximumCost(graph, i, 1 << i, k));

    return ans;
  }

  private Integer[][] dp;

  private int maximumCost(List<Pair<Integer, Integer>>[] graph, int u, int mask, int k) {
    if (Integer.bitCount(mask) == k + 1)
      return 0;
    if (dp[u][mask] != null)
      return dp[u][mask];

    int ans = -1;
    for (Pair<Integer, Integer> pair : graph[u]) {
      final int v = pair.getKey();
      final int w = pair.getValue();
      if ((mask >> v & 1) == 1)
        continue;
      final int res = maximumCost(graph, v, mask | 1 << v, k);
      if (res != -1)
        ans = Math.max(ans, w + res);
    }
    return dp[u][mask] = ans;
  }
}
