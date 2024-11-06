class Solution {
  public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
    final int n = values.length;
    List<Pair<Integer, Integer>>[] graph = new List[n];
    int[] seen = new int[n];
    seen[0] = 1;

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int time = edge[2];
      graph[u].add(new Pair<>(v, time));
      graph[v].add(new Pair<>(u, time));
    }

    dfs(graph, values, 0, values[0], maxTime, seen);
    return ans;
  }

  private int ans = 0;

  private void dfs(List<Pair<Integer, Integer>>[] graph, int[] values, int u, int quality,
                   int remainingTime, int[] seen) {
    if (u == 0)
      ans = Math.max(ans, quality);
    for (Pair<Integer, Integer> pair : graph[u]) {
      final int v = pair.getKey();
      final int time = pair.getValue();
      if (time > remainingTime)
        continue;
      final int newQuality = quality + values[v] * (seen[v] == 0 ? 1 : 0);
      ++seen[v];
      dfs(graph, values, v, newQuality, remainingTime - time, seen);
      --seen[v];
    }
  }
}
