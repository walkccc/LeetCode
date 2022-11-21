class Solution {
  public int maximumDetonation(int[][] bombs) {
    final int n = bombs.length;
    int ans = 0;
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        final long ri = bombs[i][2];
        if (ri * ri >= squaredDist(bombs, i, j))
          graph[i].add(j);
      }
    }

    for (int i = 0; i < n; ++i) {
      Set<Integer> seen = new HashSet<>(Arrays.asList(i));
      dfs(graph, i, seen);
      ans = Math.max(ans, seen.size());
    }

    return ans;
  }

  private void dfs(List<Integer>[] graph, int u, Set<Integer> seen) {
    for (final int v : graph[u]) {
      if (seen.contains(v))
        continue;
      seen.add(v);
      dfs(graph, v, seen);
    }
  }
  private long squaredDist(int[][] bombs, int i, int j) {
    return (long) (bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) +
        (long) (bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
  };
}
