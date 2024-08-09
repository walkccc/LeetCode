class Solution {
  public int[] countServers(int n, int[][] logs, int x, int[] queries) {
    int[] ans = new int[queries.length];
    int[] count = new int[n + 1];

    Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));

    int i = 0;
    int j = 0;
    int servers = 0;

    // For each query, we care about logs[i..j].
    for (IndexedQuery indexedQuery : getIndexedQueries(queries)) {
      final int queryIndex = indexedQuery.queryIndex;
      final int query = indexedQuery.query;
      for (; j < logs.length && logs[j][1] <= query; ++j)
        if (++count[logs[j][0]] == 1)
          ++servers;
      for (; i < logs.length && logs[i][1] < query - x; ++i)
        if (--count[logs[i][0]] == 0)
          --servers;
      ans[queryIndex] = n - servers;
    }

    return ans;
  }

  private record IndexedQuery(int queryIndex, int query){};

  private IndexedQuery[] getIndexedQueries(int[] queries) {
    IndexedQuery[] indexedQueries = new IndexedQuery[queries.length];
    for (int i = 0; i < queries.length; ++i)
      indexedQueries[i] = new IndexedQuery(i, queries[i]);
    Arrays.sort(indexedQueries, (a, b) -> a.query - b.query);
    return indexedQueries;
  }
}
