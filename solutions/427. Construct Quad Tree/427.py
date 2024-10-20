class Solution:
  def construct(self, grid: list[list[int]]) -> 'Node':
    return self._helper(grid, 0, 0, len(grid))

  def _helper(self, grid: list[list[int]], i: int, j: int, w: int) -> 'Node':
    if self._allSame(grid, i, j, w):
      return Node(grid[i][j] == 1, True)
    half = w // 2
    return Node(True, False,
                self._helper(grid, i, j, half),
                self._helper(grid, i, j + half, half),
                self._helper(grid, i + half, j, half),
                self._helper(grid, i + half, j + half, half))

  def _allSame(self, grid: list[list[int]], i: int, j: int, w: int) -> bool:
    return all(grid[x][y] == grid[i][j]
               for x in range(i, i + w)
               for y in range(j, j + w))
