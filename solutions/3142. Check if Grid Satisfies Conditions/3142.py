class Solution:
  def satisfiesConditions(self, grid: list[list[int]]) -> bool:
    m = len(grid)
    n = len(grid[0])
    return (all(grid[i][j] == grid[i + 1][j]
                for i in range(m - 1)
                for j in range(n)) and
            all(grid[i][j] != grid[i][j + 1]
                for i in range(m)
                for j in range(n - 1)))
