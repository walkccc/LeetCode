class Solution:
  def maxProfit(self, prices: list[int], fee: int) -> int:
    sell = 0
    hold = -math.inf

    for price in prices:
      sell = max(sell, hold + price)
      hold = max(hold, sell - price - fee)

    return sell
