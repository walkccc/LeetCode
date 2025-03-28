class Solution:
  def findColumnWidth(self, grid: list[list[int]]) -> list[int]:
    return [max(map(len, map(str, col))) for col in zip(*grid)]
