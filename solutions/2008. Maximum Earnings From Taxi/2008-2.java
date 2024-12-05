class Solution {
  public long maxTaxiEarnings(int n, int[][] rides) {
    List<Pair<Integer, Integer>>[] endToStartAndEarns = new List[n + 1];
    // dp[i] := the maximum dollars you can earn ending in i
    long[] dp = new long[n + 1];

    for (int i = 1; i <= n; ++i)
      endToStartAndEarns[i] = new ArrayList<>();

    for (int[] ride : rides) {
      final int start = ride[0];
      final int end = ride[1];
      final int tip = ride[2];
      final int earn = end - start + tip;
      endToStartAndEarns[end].add(new Pair<>(start, earn));
    }

    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1];
      for (Pair<Integer, Integer> pair : endToStartAndEarns[i]) {
        final int start = pair.getKey();
        final int earn = pair.getValue();
        dp[i] = Math.max(dp[i], dp[start] + earn);
      }
    }

    return dp[n];
  }
}
