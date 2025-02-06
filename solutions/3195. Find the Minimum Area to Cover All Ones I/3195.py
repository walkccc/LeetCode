class Solution:
  def minimumArea(self, grid: list[list[int]]) -> int:
    x1 = math.inf
    y1 = math.inf
    x2 = 0
    y2 = 0

    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        if num == 1:
          x1 = min(x1, i)
          y1 = min(y1, j)
          x2 = max(x2, i)
          y2 = max(y2, j)

    return (x2 - x1 + 1) * (y2 - y1 + 1)
