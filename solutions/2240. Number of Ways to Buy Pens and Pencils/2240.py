class Solution:
  def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
    maxPen = total // cost1
    return sum((total - i * cost1) // cost2
               for i in range(maxPen + 1)) + maxPen + 1
