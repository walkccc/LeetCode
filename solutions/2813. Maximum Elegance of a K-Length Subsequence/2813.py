class Solution:
  def findMaximumElegance(self, items: list[list[int]], k: int) -> int:
    ans = 0
    totalProfit = 0
    seenCategories = set()
    decreasingDuplicateProfits = []

    items.sort(reverse=True)

    for i in range(k):
      profit, category = items[i]
      totalProfit += profit
      if category in seenCategories:
        decreasingDuplicateProfits.append(profit)
      else:
        seenCategories.add(category)

    ans = totalProfit + len(seenCategories)**2

    for i in range(k, len(items)):
      profit, category = items[i]
      if category not in seenCategories and decreasingDuplicateProfits:
        # If this is a new category we haven't seen before, it's worth
        # considering taking it and replacing the one with the least profit
        # since it will increase the distinct_categories and potentially result
        # in a larger total_profit + distinct_categories^2.
        totalProfit -= decreasingDuplicateProfits.pop()
        totalProfit += profit
        seenCategories.add(category)
        ans = max(ans, totalProfit + len(seenCategories)**2)

    return ans
