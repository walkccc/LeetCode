class Solution:
  def specialGrid(self, n: int) -> list[list[int]]:
    sz = 1 << n
    grid = [[0] * sz for _ in range(sz)]
    count = 0

    def fill(x1: int, x2: int, y1: int, y2: int) -> None:
      nonlocal count
      if x2 - x1 == 1:
        grid[x1][y1] = count
        count += 1
        return
      midRow = (x1 + x2) // 2
      midCol = (y1 + y2) // 2
      fill(x1, midRow, midCol, y2)
      fill(midRow, x2, midCol, y2)
      fill(midRow, x2, y1, midCol)
      fill(x1, midRow, y1, midCol)

    fill(0, sz, 0, sz)
    return grid
