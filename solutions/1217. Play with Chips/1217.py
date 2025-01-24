class Solution:
  def minCostToMoveChips(self, position: list[int]) -> int:
    count = [0, 0]
    for p in position:
      count[p % 2] += 1
    return min(count[0], count[1])
