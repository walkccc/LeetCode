class Solution {
  public int[] countServers(int n, int[][] logs, int x, int[] queries) {
    int[] ans = new int[queries.length];
    int[] count = new int[n + 1];
    Pair<Integer, Integer>[] queryAndIndexes = new Pair[queries.length];

    for (int i = 0; i < queries.length; ++i)
      queryAndIndexes[i] = new Pair<>(queries[i], i);

    Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));
    Arrays.sort(queryAndIndexes, Comparator.comparingInt(Pair::getKey));

    int i = 0;
    int j = 0;
    int servers = 0;

    // For each query, we care about logs[i..j].
    for (Pair<Integer, Integer> queryAndIndex : queryAndIndexes) {
      final int query = queryAndIndex.getKey();
      final int index = queryAndIndex.getValue();
      for (; j < logs.length && logs[j][1] <= query; ++j)
        if (++count[logs[j][0]] == 1)
          ++servers;
      for (; i < logs.length && logs[i][1] < query - x; ++i)
        if (--count[logs[i][0]] == 0)
          --servers;
      ans[index] = n - servers;
    }

    return ans;
  }
}
