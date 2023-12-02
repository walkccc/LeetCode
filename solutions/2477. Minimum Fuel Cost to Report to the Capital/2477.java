class Solution {
  public long minimumFuelCost(int[][] roads, int seats) {
    List<Integer>[] tree = new List[roads.length + 1];

    for (int i = 0; i < tree.length; ++i)
      tree[i] = new ArrayList<>();

    for (int[] road : roads) {
      final int u = road[0];
      final int v = road[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    dfs(tree, 0, -1, seats);
    return ans;
  }

  private long ans = 0;

  private int dfs(List<Integer>[] tree, int u, int prev, int seats) {
    int people = 1;
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      people += dfs(tree, v, u, seats);
    }
    if (u > 0)
      // the number of cars needed = ceil(people / seats)
      ans += (people + seats - 1) / seats;
    return people;
  }
}
