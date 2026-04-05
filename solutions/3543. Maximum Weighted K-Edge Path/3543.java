class Solution {
  public int maxWeight(int n, int[][] edges, int k, int t) {
    List<Pair<Integer, Integer>>[] graph = new List[n];
    // dp[i][j] := the set of possible path sums ending at node i with j edges
    Map<Integer, Set<Integer>>[] dp = new Map[n];

    for (int u = 0; u < n; ++u) {
      graph[u] = new ArrayList<>();
      dp[u] = new HashMap<>();
    }

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
    }

    for (int u = 0; u < n; ++u) {
      dp[u].putIfAbsent(0, new HashSet<>());
      dp[u].get(0).add(0); // zero edges = sum 0
    }

    for (int i = 0; i < k; ++i)
      for (int u = 0; u < n; ++u)
        if (dp[u].containsKey(i))
          for (final int currSum : dp[u].get(i))
            for (Pair<Integer, Integer> pair : graph[u]) {
              final int v = pair.getKey();
              final int w = pair.getValue();
              final int newSum = currSum + w;
              if (newSum < t) {
                dp[v].putIfAbsent(i + 1, new HashSet<>());
                dp[v].get(i + 1).add(newSum);
              }
            }

    int ans = -1;

    for (int u = 0; u < n; ++u)
      if (dp[u].containsKey(k))
        for (final int sum : dp[u].get(k))
          ans = Math.max(ans, sum);

    return ans;
  }
}
