
class Solution:
  def minimumSum(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = m * n

    for i in range(m):
      top = self._minimumArea(grid, 0, i, 0, n - 1)
      for j in range(n):
        ans = min(ans, top +
                  self._minimumArea(grid, i + 1, m - 1, 0, j) +
                  self._minimumArea(grid, i + 1, m - 1, j + 1, n - 1))

    for i in range(m):
      bottom = self._minimumArea(grid, i, m - 1, 0, n - 1)
      for j in range(n):
        ans = min(ans, bottom +
                  self._minimumArea(grid, 0, i - 1, 0, j) +
                  self._minimumArea(grid, 0, i - 1, j + 1, n - 1))

    for j in range(n):
      left = self._minimumArea(grid, 0, m - 1, 0, j)
      for i in range(m):
        ans = min(ans, left +
                  self._minimumArea(grid, 0, i, j + 1, n - 1) +
                  self._minimumArea(grid, i + 1, m - 1, j + 1, n - 1))

    for j in range(n):
      right = self._minimumArea(grid, 0, m - 1, j, n - 1)
      for i in range(m):
        ans = min(ans, right +
                  self._minimumArea(grid, 0, i, 0, j - 1) +
                  self._minimumArea(grid, i + 1, m - 1, 0, j - 1))

    for i1 in range(m):
      for i2 in range(i1 + 1, m):
        ans = min(ans, self._minimumArea(grid, 0, i1, 0, n - 1) +
                  self._minimumArea(grid, i1 + 1, i2, 0, n - 1) +
                  self._minimumArea(grid, i2 + 1, m - 1, 0, n - 1))

    for j1 in range(n):
      for j2 in range(j1 + 1, n):
        ans = min(ans, self._minimumArea(grid, 0, m - 1, 0, j1) +
                  self._minimumArea(grid, 0, m - 1, j1 + 1, j2) +
                  self._minimumArea(grid, 0, m - 1, j2 + 1, n - 1))

    return ans

  def _minimumArea(
      self,
      grid: list[list[int]],
      si: int,
      ei: int,
      sj: int,
      ej: int,
  ) -> int:
    x1 = math.inf
    y1 = math.inf
    x2 = 0
    y2 = 0
    for i in range(si, ei + 1):
      for j in range(sj, ej + 1):
        if grid[i][j] == 1:
          x1 = min(x1, i)
          y1 = min(y1, j)
          x2 = max(x2, i)
          y2 = max(y2, j)
    return 0 if x1 == math.inf else (x2 - x1 + 1) * (y2 - y1 + 1)
