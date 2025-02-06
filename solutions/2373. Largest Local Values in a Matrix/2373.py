class Solution:
  def largestLocal(self, grid: list[list[int]]) -> list[list[int]]:
    n = len(grid)
    ans = [[0] * (n - 2) for _ in range(n - 2)]

    for i in range(n - 2):
      for j in range(n - 2):
        for x in range(i, i + 3):
          for y in range(j, j + 3):
            ans[i][j] = max(ans[i][j], grid[x][y])

    return ans
