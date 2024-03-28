from sortedcontainers import SortedSet


class Solution:
  def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
    m = len(grid)
    n = len(grid[0])
    sums = SortedSet()

    for i in range(m):
      for j in range(n):
        sz = 0
        while i + sz < m and i - sz >= 0 and j + 2 * sz < n:
          summ = grid[i][j] if sz == 0 else self._getSum(grid, i, j, sz)
          sums.add(summ)
          if len(sums) > 3:
            sums.pop(0)
          sz += 1

    return sums

  def _getSum(self, grid: List[List[int]], i: int, j: int, sz: int) -> int:
    """
    Returns the sum of the rhombus, where the top grid is (i, j) and the edge
    size is `sz`.
    """
    x = i
    y = j
    summ = 0

    # Go left down.
    for _ in range(sz):
      x -= 1
      y += 1
      summ += grid[x][y]

    # Go right down.
    for _ in range(sz):
      x += 1
      y += 1
      summ += grid[x][y]

    # Go right up.
    for _ in range(sz):
      x += 1
      y -= 1
      summ += grid[x][y]

    # Go left up.
    for _ in range(sz):
      x -= 1
      y -= 1
      summ += grid[x][y]

    return summ
