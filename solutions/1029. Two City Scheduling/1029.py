class Solution:
  def twoCitySchedCost(self, costs: List[List[int]]) -> int:
    n = len(costs) // 2

    # How much money can we save if we fly a person to A instead of B?
    # To save money, we should
    #   1. Fly the person with the maximum saving to A.
    #   2. Fly the person with the minimum saving to B.

    # Sort `costs` in descending order by the money saved if we fly a person
    # to A instead of B.
    costs.sort(key=lambda x: x[0] - x[1])
    return sum(costs[i][0] + costs[i + n][1] for i in range(n))
