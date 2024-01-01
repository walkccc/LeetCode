class Solution:
  def findChampion(self, grid: List[List[int]]) -> int:
    return max(range(len(grid)), key=lambda i: sum(grid[i]))
