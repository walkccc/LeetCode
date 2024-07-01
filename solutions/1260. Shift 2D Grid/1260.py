class Solution:
  def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
    m = len(grid)
    n = len(grid[0])
    ans = [[0] * n for _ in range(m)]

    k %= m * n

    for i in range(m):
      for j in range(n):
        index = (i * n + j + k) % (m * n)
        x = index // n
        y = index % n
        ans[x][y] = grid[i][j]

    return ans
