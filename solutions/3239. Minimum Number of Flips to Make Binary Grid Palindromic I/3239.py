class Solution:
  def minFlips(self, grid: list[list[int]]) -> int:
    rowFlips = sum(row[i] != row[-1 - i]
                   for row in grid for i in range(len(row) // 2))
    colFlips = sum(col[i] != col[-1 - i] for col in zip(*grid)
                   for i in range(len(col) // 2))
    return min(rowFlips, colFlips)
