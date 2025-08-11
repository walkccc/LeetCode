class Solution {
  public int connectTwoGroups(List<List<Integer>> cost) {
    final int m = cost.size();
    final int n = cost.get(0).size();
    Integer[][] mem = new Integer[m][1 << n];
    // minCosts[j] := the minimum cost of connecting group2's point j
    int[] minCosts = new int[n];

    for (int j = 0; j < n; ++j) {
      int minCostIndex = 0;
      for (int i = 1; i < m; ++i)
        if (cost.get(i).get(j) < cost.get(minCostIndex).get(j))
          minCostIndex = i;
      minCosts[j] = cost.get(minCostIndex).get(j);
    }

    return connectTwoGroups(cost, 0, 0, minCosts, mem);
  }

  // Returns the minimum cost to connect group1's points[i..n) with group2's
  // points, where `mask` is the bitmask of the connected points in group2.
  private int connectTwoGroups(List<List<Integer>> cost, int i, int mask, int[] minCosts,
                               Integer[][] mem) {
    if (i == cost.size()) {
      // All the points in group 1 are connected, so greedily assign the
      // minimum cost for the unconnected points of group2.
      int res = 0;
      for (int j = 0; j < cost.get(0).size(); ++j)
        if ((mask >> j & 1) == 0)
          res += minCosts[j];
      return res;
    }
    if (mem[i][mask] != null)
      return mem[i][mask];

    int res = Integer.MAX_VALUE;
    for (int j = 0; j < cost.get(0).size(); ++j)
      res = Math.min(res, cost.get(i).get(j) +
                              connectTwoGroups(cost, i + 1, mask | 1 << j, minCosts, mem));
    return mem[i][mask] = res;
  }
}
