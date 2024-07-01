class Solution {
  public long minimumCost(String source, String target, char[] original, char[] changed,
                          int[] cost) {
    long ans = 0;
    // dist[u][v] := the minimum distance to change ('a' + u) to ('a' + v)
    long[][] dist = new long[26][26];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Long.MAX_VALUE));

    for (int i = 0; i < cost.length; ++i) {
      final int u = original[i] - 'a';
      final int v = changed[i] - 'a';
      dist[u][v] = Math.min(dist[u][v], cost[i]);
    }

    for (int k = 0; k < 26; ++k)
      for (int i = 0; i < 26; ++i)
        if (dist[i][k] < Long.MAX_VALUE)
          for (int j = 0; j < 26; ++j)
            if (dist[k][j] < Long.MAX_VALUE)
              dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < source.length(); ++i) {
      if (source.charAt(i) == target.charAt(i))
        continue;
      final int u = source.charAt(i) - 'a';
      final int v = target.charAt(i) - 'a';
      if (dist[u][v] == Long.MAX_VALUE)
        return -1;
      ans += dist[u][v];
    }

    return ans;
  }
}
