class Solution:
  def minCostToMoveChips(self, position: List[int]) -> int:
    count = [0] * 2
    for p in position:
      count[p % 2] += 1
    return min(count[0], count[1])
