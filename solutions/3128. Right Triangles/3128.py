class Solution:
  def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
    rows = [0] * len(grid)
    cols = [0] * len(grid[0])

    for i, row in enumerate(grid):
      for j, cell in enumerate(row):
        if cell == 1:
          rows[i] += 1
          cols[j] += 1

    return sum((rows[i] - 1) * (cols[j] - 1)
               for i, row in enumerate(grid)
               for j, cell in enumerate(row)
               if cell == 1)
