class Solution:
  def minPathSum(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])

    for i in range(m):
      for j in range(n):
        if i > 0 and j > 0:
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])
        elif i > 0:
          grid[i][0] += grid[i - 1][0]
        elif j > 0:
          grid[0][j] += grid[0][j - 1]

    return grid[m - 1][n - 1]
