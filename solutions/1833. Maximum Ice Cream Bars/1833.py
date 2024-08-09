class Solution:
  def maxIceCream(self, costs: List[int], coins: int) -> int:
    for i, cost in enumerate(sorted(costs)):
      if coins >= cost:
        coins -= cost
      else:
        return i

    return len(costs)
