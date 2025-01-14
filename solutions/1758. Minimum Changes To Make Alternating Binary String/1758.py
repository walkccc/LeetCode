class Solution:
  def minOperations(self, s: str) -> int:
    # the cost to make s "1010"
    cost10 = sum(int(c) == i % 2 for i, c in enumerate(s))
    # the cost to make s "0101"
    cost01 = len(s) - cost10
    return min(cost10, cost01)
