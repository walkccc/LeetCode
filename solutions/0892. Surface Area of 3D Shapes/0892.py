class Solution:
  def surfaceArea(self, grid: List[List[int]]) -> int:
    ans = 0

    for i in range(len(grid)):
      for j in range(len(grid)):
        if grid[i][j]:
          ans += grid[i][j] * 4 + 2
        if i:
          ans -= min(grid[i][j], grid[i - 1][j]) * 2
        if j:
          ans -= min(grid[i][j], grid[i][j - 1]) * 2

    return ans
