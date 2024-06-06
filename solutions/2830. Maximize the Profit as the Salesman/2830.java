class Solution {
  public int maximizeTheProfit(int n, List<List<Integer>> offers) {
    // dp[i] := the maximum amount of gold of selling the first i houses
    int[] dp = new int[n + 1];
    List<Pair<Integer, Integer>>[] endToStartAndGolds = new List[n];

    for (int i = 0; i < n; ++i)
      endToStartAndGolds[i] = new ArrayList<>();

    for (List<Integer> offer : offers) {
      final int start = offer.get(0);
      final int end = offer.get(1);
      final int gold = offer.get(2);
      endToStartAndGolds[end].add(new Pair<>(start, gold));
    }

    for (int end = 1; end <= n; ++end) {
      // Get at least the same gold as selling the first `end - 1` houses.
      dp[end] = dp[end - 1];
      for (Pair<Integer, Integer> pair : endToStartAndGolds[end - 1]) {
        final Integer start = pair.getKey();
        final Integer gold = pair.getValue();
        dp[end] = Math.max(dp[end], dp[start] + gold);
      }
    }

    return dp[n];
  }
}
