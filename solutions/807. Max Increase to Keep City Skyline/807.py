class Solution:
  def maxIncreaseKeepingSkyline(self, grid: list[list[int]]) -> int:
    rowMax = list(map(max, grid))
    colMax = list(map(max, zip(*grid)))
    return sum(min(i, j) for i in rowMax for j in colMax) - sum(map(sum, grid))
