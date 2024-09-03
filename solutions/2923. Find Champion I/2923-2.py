class Solution:
  def findChampion(self, grid: list[list[int]]) -> int:
    return max(range(len(grid)), key=lambda i: sum(grid[i]))
