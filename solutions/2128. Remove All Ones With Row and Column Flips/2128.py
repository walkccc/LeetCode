class Solution:
  def removeOnes(self, grid: list[list[int]]) -> bool:
    revRow = [a ^ 1 for a in grid[0]]
    return all(row == grid[0] or row == revRow for row in grid)
