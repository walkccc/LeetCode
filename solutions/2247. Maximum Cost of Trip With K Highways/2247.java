class Solution {
  public int maximumCost(int n, int[][] highways, int k) {
    if (k + 1 > n)
      return -1;

    int ans = -1;
    Integer[][] mem = new Integer[n][1 << n];
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
      ans = Math.max(ans, maximumCost(graph, i, 1 << i, k, mem));

    return ans;
  }

  // Returns the maximum cost of trip starting from u, where `mask` is the
  // bitmask of the visited cities.
  private int maximumCost(List<Pair<Integer, Integer>>[] graph, int u, int mask, int k,
                          Integer[][] mem) {
    if (Integer.bitCount(mask) == k + 1)
      return 0;
    if (mem[u][mask] != null)
      return mem[u][mask];

    int res = -1;
    for (Pair<Integer, Integer> pair : graph[u]) {
      final int v = pair.getKey();
      final int w = pair.getValue();
      if ((mask >> v & 1) == 1)
        continue;
      final int nextCost = maximumCost(graph, v, mask | 1 << v, k, mem);
      if (nextCost != -1)
        res = Math.max(res, w + nextCost);
    }

    return mem[u][mask] = res;
  }
}
