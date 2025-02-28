class Solution:
  def maxProfit(self, prices: list[int]) -> int:
    sellOne = 0
    holdOne = -math.inf

    for price in prices:
      sellOne = max(sellOne, holdOne + price)
      holdOne = max(holdOne, -price)

    return sellOne
