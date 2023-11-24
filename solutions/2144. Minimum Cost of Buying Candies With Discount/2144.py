class Solution:
  def minimumCost(self, cost: List[int]) -> int:
    return sum(cost) - sum(sorted(cost)[-3::-3])
