class Solution {
  public long minimumCost(String source, String target, String[] original, String[] changed,
                          int[] cost) {
    Set<Integer> subLengths = getSubLengths(original);
    Map<String, Integer> subToId = getSubToId(original, changed);
    final int subCount = subToId.size();
    // dist[u][v] := the minimum distance to change the substring with id u to
    // the substring with id v
    long[][] dist = new long[subCount][subCount];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Long.MAX_VALUE));
    // dp[i] := the minimum cost to change the first i letters of `source` into
    // `target`, leaving the suffix untouched
    long[] dp = new long[source.length() + 1];
    Arrays.fill(dp, Long.MAX_VALUE);

    for (int i = 0; i < cost.length; ++i) {
      final int u = subToId.get(original[i]);
      final int v = subToId.get(changed[i]);
      dist[u][v] = Math.min(dist[u][v], (long) cost[i]);
    }

    for (int k = 0; k < subCount; ++k)
      for (int i = 0; i < subCount; ++i)
        if (dist[i][k] < Long.MAX_VALUE)
          for (int j = 0; j < subCount; ++j)
            if (dist[k][j] < Long.MAX_VALUE)
              dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

    dp[0] = 0;

    for (int i = 0; i < source.length(); ++i) {
      if (dp[i] == Long.MAX_VALUE)
        continue;
      if (target.charAt(i) == source.charAt(i))
        dp[i + 1] = Math.min(dp[i + 1], dp[i]);
      for (int subLength : subLengths) {
        if (i + subLength > source.length())
          continue;
        String subSource = source.substring(i, i + subLength);
        String subTarget = target.substring(i, i + subLength);
        if (!subToId.containsKey(subSource) || !subToId.containsKey(subTarget))
          continue;
        final int u = subToId.get(subSource);
        final int v = subToId.get(subTarget);
        if (dist[u][v] < Long.MAX_VALUE)
          dp[i + subLength] = Math.min(dp[i + subLength], dp[i] + dist[u][v]);
      }
    }

    return dp[source.length()] == Long.MAX_VALUE ? -1 : dp[source.length()];
  }

  private Map<String, Integer> getSubToId(String[] original, String[] changed) {
    Map<String, Integer> subToId = new HashMap<>();
    for (final String s : original)
      subToId.putIfAbsent(s, subToId.size());
    for (final String s : changed)
      subToId.putIfAbsent(s, subToId.size());
    return subToId;
  }

  private Set<Integer> getSubLengths(String[] original) {
    Set<Integer> subLengths = new HashSet<>();
    for (final String s : original)
      subLengths.add(s.length());
    return subLengths;
  }
}
