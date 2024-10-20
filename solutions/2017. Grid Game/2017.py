class Solution:
  def gridGame(self, grid: list[list[int]]) -> int:
    n = len(grid[0])
    ans = math.inf
    sumRow0 = sum(grid[0])
    sumRow1 = 0

    for i in range(n):
      sumRow0 -= grid[0][i]
      ans = min(ans, max(sumRow0, sumRow1))
      sumRow1 += grid[1][i]

    return ans
