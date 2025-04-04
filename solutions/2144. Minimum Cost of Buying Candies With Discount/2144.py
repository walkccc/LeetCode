class Solution:
  def minimumCost(self, cost: list[int]) -> int:
    return sum(cost) - sum(sorted(cost)[-3::-3])
