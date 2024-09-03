class Solution:
  def checkValidGrid(self, grid: list[list[int]]) -> bool:
    dirs = ((1, 2), (2, 1), (2, -1), (1, -2),
            (-1, -2), (-2, -1), (-2, 1), (-1, 2))
    n = len(grid)
    i = 0
    j = 0

    def nextGrid(i: int, j: int, target: int) -> tuple[int, int]:
      """
      Returns (x, y), where grid[x][y] == target if (i, j) can reach target.
      """
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x >= n or y < 0 or y >= n:
          continue
        if grid[x][y] == target:
          return (x, y)
      return (-1, -1)

    for target in range(1, n * n):
      x, y = nextGrid(i, j, target)
      if x == -1 and y == -1:
        return False
      # Move (x, y) to (i, j).
      i = x
      j = y

    return True
