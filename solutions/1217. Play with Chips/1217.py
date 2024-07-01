class Solution:
  def minCostToMoveChips(self, chips: List[int]) -> int:
    count = [0] * 2

    for chip in chips:
      count[chip % 2] += 1

    return min(count[0], count[1])
