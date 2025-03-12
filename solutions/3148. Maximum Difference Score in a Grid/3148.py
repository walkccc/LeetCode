class Solution:
  def maxScore(self, grid: list[list[int]]) -> int:
    MAX = 200000
    ans = -MAX

    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        prevMin = min(grid[i - 1][j] if i > 0 else MAX,
                      grid[i][j - 1] if j > 0 else MAX)
        ans = max(ans, num - prevMin)
        grid[i][j] = min(num, prevMin)

    return ans
