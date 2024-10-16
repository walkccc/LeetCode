class ChildCost {
  public ChildCost(int cost) {
    if (cost > 0)
      maxPosCosts.add(cost);
    else
      minNegCosts.add(cost);
  }

  public void update(ChildCost childCost) {
    numNodes += childCost.numNodes;
    maxPosCosts.addAll(childCost.maxPosCosts);
    minNegCosts.addAll(childCost.minNegCosts);
    maxPosCosts.sort(Comparator.reverseOrder());
    minNegCosts.sort(Comparator.naturalOrder());
    if (maxPosCosts.size() > 3)
      maxPosCosts = maxPosCosts.subList(0, 3);
    if (minNegCosts.size() > 2)
      minNegCosts = minNegCosts.subList(0, 2);
  }

  public long maxProduct() {
    if (numNodes < 3)
      return 1;
    if (maxPosCosts.isEmpty())
      return 0;
    long res = 0;
    if (maxPosCosts.size() == 3)
      res = (long) maxPosCosts.get(0) * maxPosCosts.get(1) * maxPosCosts.get(2);
    if (minNegCosts.size() == 2)
      res = Math.max(res, (long) minNegCosts.get(0) * minNegCosts.get(1) * maxPosCosts.get(0));
    return res;
  }

  private int numNodes = 1;
  private List<Integer> maxPosCosts = new ArrayList<>();
  private List<Integer> minNegCosts = new ArrayList<>();
}

class Solution {
  public long[] placedCoins(int[][] edges, int[] cost) {
    final int n = cost.length;
    long[] ans = new long[n];
    List<Integer>[] tree = new List[n];

    for (int i = 0; i < n; i++)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    dfs(tree, 0, /*prev=*/-1, cost, ans);
    return ans;
  }

  private ChildCost dfs(List<Integer>[] tree, int u, int prev, int[] cost, long[] ans) {
    ChildCost res = new ChildCost(cost[u]);
    for (final int v : tree[u])
      if (v != prev)
        res.update(dfs(tree, v, u, cost, ans));
    ans[u] = res.maxProduct();
    return res;
  }
}
