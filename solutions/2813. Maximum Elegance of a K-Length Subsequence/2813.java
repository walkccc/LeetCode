class Solution {
  public long findMaximumElegance(int[][] items, int k) {
    long ans = 0;
    long totalProfit = 0;
    Set<Integer> seenCategories = new HashSet<>();
    Deque<Integer> decreasingDuplicateProfits = new ArrayDeque<>();

    Arrays.sort(items, (a, b) -> Integer.compare(b[0], a[0]));

    for (int i = 0; i < k; ++i) {
      final int profit = items[i][0];
      final int category = items[i][1];
      totalProfit += profit;
      if (seenCategories.contains(category))
        decreasingDuplicateProfits.push(profit);
      else
        seenCategories.add(category);
    }

    ans = totalProfit + 1L * seenCategories.size() * seenCategories.size();

    for (int i = k; i < items.length; ++i) {
      final int profit = items[i][0];
      final int category = items[i][1];
      if (!seenCategories.contains(category) && !decreasingDuplicateProfits.isEmpty()) {
        // If this is a new category we haven't seen before, it's worth
        // considering taking it and replacing the one with the least profit
        // since it will increase the distinct_categories and potentially result
        // in a larger total_profit + distinct_categories^2.
        totalProfit -= decreasingDuplicateProfits.pop();
        totalProfit += profit;
        seenCategories.add(category);
        ans = Math.max(ans, totalProfit + 1L * seenCategories.size() * seenCategories.size());
      }
    }

    return ans;
  }
}
