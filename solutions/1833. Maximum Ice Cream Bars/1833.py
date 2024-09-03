class Solution:
  def maxIceCream(self, costs: list[int], coins: int) -> int:
    for i, cost in enumerate(sorted(costs)):
      if coins >= cost:
        coins -= cost
      else:
        return i

    return len(costs)
