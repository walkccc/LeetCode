class Solution:
  def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
    return [max(map(len, map(str, col))) for col in zip(*grid)]
