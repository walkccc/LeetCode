class Solution {
  public long maxScore(int[] prices) {
    //    prices[indexes[j]] - prices[indexes[j - 1]]
    // == indexes[j] - indexes[j - 1]
    //    prices[indexes[j]] - indexes[j]
    // == prices[indexes[j - 1]] - indexes[j - 1]
    //
    // So, elements in the same subsequence must have the same prices[i] - i.
    Map<Integer, Long> groupIdToSum = new HashMap<>();

    for (int i = 0; i < prices.length; ++i)
      groupIdToSum.merge(prices[i] - i, (long) prices[i], Long::sum);

    return groupIdToSum.values().stream().max(Long::compare).orElse(0L);
  }
}
