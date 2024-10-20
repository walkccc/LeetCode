class Solution:
  def fillCups(self, amount: list[int]) -> int:
    return max(max(amount), (sum(amount) + 1) // 2)
