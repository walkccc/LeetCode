class Solution:
  def maxSum(self, grid: List[List[int]]) -> int:
    return max(grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] + grid[i][j] +
               grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1]
               for i in range(1, len(grid) - 1)
               for j in range(1, len(grid[0]) - 1))
