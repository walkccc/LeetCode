class Solution:
  def maxScore(self, grid: list[list[int]]) -> int:
    kMax = 200000
    ans = -kMax

    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        prevMin = min(grid[i - 1][j] if i > 0 else kMax,
                      grid[i][j - 1] if j > 0 else kMax)
        ans = max(ans, num - prevMin)
        grid[i][j] = min(num, prevMin)

    return ans
