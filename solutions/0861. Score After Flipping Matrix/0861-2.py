class Solution:
  def matrixScore(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = m  # all cells in the first col are 1

    for j in range(1, n):
      # the best strategy is flip a row with leading 0
      onesCount = sum(grid[i][j] == grid[i][0] for i in range(m))
      ans = ans * 2 + max(onesCount, m - onesCount)

    return ans
