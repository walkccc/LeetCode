class Solution {
  public int[] countPairs(int n, int[][] edges, int[] queries) {
    int[] ans = new int[queries.length];

    // count[i] := the number of edges of node i
    int[] count = new int[n + 1];

    // shared[i][j] := the number of edges incident to i or j, where i < j
    Map<Integer, Integer>[] shared = new Map[n + 1];

    for (int i = 1; i <= n; ++i)
      shared[i] = new HashMap<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      ++count[u];
      ++count[v];
      shared[Math.min(u, v)].merge(Math.max(u, v), 1, Integer::sum);
    }

    int[] sortedCount = count.clone();
    Arrays.sort(sortedCount);

    int k = 0;
    for (final int query : queries) {
      for (int i = 1, j = n; i < j;)
        if (sortedCount[i] + sortedCount[j] > query)
          // sortedCount[i] + sortedCount[j] > query
          // sortedCount[i + 1] + sortedCount[j] > query
          // ...
          // sortedCount[j - 1] + sortedCount[j] > query
          // So, there are (j - 1) - i + 1 = j - i pairs > query
          ans[k] += (j--) - i;
        else
          ++i;
      for (int i = 1; i <= n; ++i)
        for (Map.Entry<Integer, Integer> p : shared[i].entrySet()) {
          final int j = p.getKey();
          final int sh = p.getValue();
          if (count[i] + count[j] > query && count[i] + count[j] - sh <= query)
            --ans[k];
        }
      ++k;
    }

    return ans;
  }
}
