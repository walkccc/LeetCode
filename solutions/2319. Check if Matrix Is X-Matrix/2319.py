class Solution:
  def checkXMatrix(self, grid: list[list[int]]) -> bool:
    n = len(grid)

    for i in range(n):
      for j in range(n):
        if i == j or i + j == n - 1:  # in diagonal
          if grid[i][j] == 0:
            return False
        elif grid[i][j]:   # not in diagonal
          return False

    return True
