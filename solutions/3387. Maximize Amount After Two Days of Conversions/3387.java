class Solution {
  public double maxAmount(String initialCurrency, List<List<String>> pairs1, double[] rates1,
                          List<List<String>> pairs2, double[] rates2) {
    // dp[currency] := the maximum amount of money to convert to `currency`
    Map<String, Double> dp = new HashMap<>();
    dp.put(initialCurrency, 1.0);
    bellman(dp, pairs1, rates1);
    bellman(dp, pairs2, rates2);
    return dp.get(initialCurrency);
  }

  private void bellman(Map<String, Double> dp, List<List<String>> pairs, double[] rates) {
    for (int relax = 0; relax < pairs.size(); ++relax)
      for (int i = 0; i < pairs.size(); ++i) {
        final String start = pairs.get(i).get(0);
        final String target = pairs.get(i).get(1);
        dp.merge(target, dp.getOrDefault(start, 0.0) * rates[i], Double::max);
        dp.merge(start, dp.getOrDefault(target, 0.0) / rates[i], Double::max);
      }
  }
}
