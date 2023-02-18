class Solution {
  public long minimumFuelCost(int[][] roads, int seats) {
    List<Integer>[] graph = new List[roads.length + 1];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] road : roads) {
      final int u = road[0];
      final int v = road[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(graph, 0, -1, seats);
    return ans;
  }

  private long ans = 0;

  private int dfs(List<Integer>[] graph, int u, int prev, int seats) {
    int people = 1;
    for (final int v : graph[u]) {
      if (v == prev)
        continue;
      people += dfs(graph, v, u, seats);
    }
    if (u > 0)
      // # of cars needed = ceil(people / seats)
      ans += (people + seats - 1) / seats;
    return people;
  }
}
