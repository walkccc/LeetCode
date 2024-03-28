class FenwickTree:
  def __init__(self, n: int):
    self.vals = [0] * (n + 1)

  def update(self, i: int, val: int) -> None:
    while i < len(self.vals):
      self.vals[i] = max(self.vals[i], val)
      i += FenwickTree.lowbit(i)

  def get(self, i: int) -> int:
    res = 0
    while i > 0:
      res = max(res, self.vals[i])
      i -= FenwickTree.lowbit(i)
    return res

  @staticmethod
  def lowbit(i: int) -> int:
    return i & -i


class Solution:
  # Same as 2907. Maximum Profitable Triplets With Increasing Prices I
  def maxProfit(self, prices: List[int], profits: List[int]) -> int:
    ans = -1
    maxPrice = max(prices)
    maxProfitTree1 = FenwickTree(maxPrice)
    maxProfitTree2 = FenwickTree(maxPrice)

    for price, profit in zip(prices, profits):
      # max(proftis[i])
      maxProfit1 = maxProfitTree1.get(price - 1)
      # max(proftis[i]) + max(profits[j])
      maxProfit2 = maxProfitTree2.get(price - 1)
      maxProfitTree1.update(price, profit)
      if maxProfit1 > 0:
        maxProfitTree2.update(price, profit + maxProfit1)
      if maxProfit2 > 0:
        ans = max(ans, profit + maxProfit2)

    return ans
