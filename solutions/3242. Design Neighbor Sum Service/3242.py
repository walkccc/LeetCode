class neighborSum:
  def __init__(self, grid: list[list[int]]):
    self.grid = grid
    self.n = len(grid)
    self.numToPos = {num: (i, j)
                     for i, row in enumerate(grid)
                     for j, num in enumerate(row)}

  def adjacentSum(self, value: int) -> int:
    i, j = self.numToPos[value]
    return sum(self.grid[x][y]
               for x, y in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1))
               if 0 <= x < self.n and 0 <= y < self.n)

  def diagonalSum(self, value: int) -> int:
    i, j = self.numToPos[value]
    return sum(self.grid[x][y]
               for x, y in ((i - 1, j - 1), (i - 1, j + 1),
                            (i + 1, j - 1), (i + 1, j + 1))
               if 0 <= x < self.n and 0 <= y < self.n)
