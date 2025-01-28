class Solution:
  def numberOfRightTriangles(self, grid: list[list[int]]) -> int:
    rows = [0] * len(grid)
    cols = [0] * len(grid[0])

    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        if num == 1:
          rows[i] += 1
          cols[j] += 1

    return sum((rows[i] - 1) * (cols[j] - 1)
               for i, row in enumerate(grid)
               for j, num in enumerate(row)
               if num == 1)
