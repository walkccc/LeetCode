class Solution:
  def countNegatives(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = 0
    i = m - 1
    j = 0

    while i >= 0 and j < n:
      if grid[i][j] < 0:
        ans += n - j
        i -= 1
      else:
        j += 1

    return ans
