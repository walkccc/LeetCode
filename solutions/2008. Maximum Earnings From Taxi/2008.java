class Solution {
  public long maxTaxiEarnings(int n, int[][] rides) {
    List<Pair<Integer, Integer>>[] startToEndAndEarns = new List[n];
    // dp[i] := the maximum dollars you can earn starting at i
    long[] dp = new long[n + 1];

    for (int i = 1; i < n; ++i)
      startToEndAndEarns[i] = new ArrayList<>();

    for (int[] ride : rides) {
      final int start = ride[0];
      final int end = ride[1];
      final int tip = ride[2];
      final int earn = end - start + tip;
      startToEndAndEarns[start].add(new Pair<>(end, earn));
    }

    for (int i = n - 1; i >= 1; --i) {
      dp[i] = dp[i + 1];
      for (Pair<Integer, Integer> pair : startToEndAndEarns[i]) {
        final int end = pair.getKey();
        final int earn = pair.getValue();
        dp[i] = Math.max(dp[i], dp[end] + earn);
      }
    }

    return dp[1];
  }
}
