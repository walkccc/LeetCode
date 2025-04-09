class Solution {
  public long maxScore(int[] prices) {
    //    prices[indices[j]] - prices[indices[j - 1]]
    // == indices[j] - indices[j - 1]
    //    prices[indices[j]] - indices[j]
    // == prices[indices[j - 1]] - indices[j - 1]
    //
    // So, elements in the same subsequence must have the same prices[i] - i.
    Map<Integer, Long> groupIdToSum = new HashMap<>();

    for (int i = 0; i < prices.length; ++i)
      groupIdToSum.merge(prices[i] - i, (long) prices[i], Long::sum);

    return groupIdToSum.values().stream().max(Long::compare).orElse(0L);
  }
}
