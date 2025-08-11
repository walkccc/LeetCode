class Solution:
  def colorBorder(
      self,
      grid: list[list[int]],
      r0: int,
      c0: int,
      color: int
  ) -> list[list[int]]:
    def dfs(i: int, j: int, startColor: int) -> None:
      if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]):
        return
      if grid[i][j] != startColor:
        return

      grid[i][j] = -startColor
      dfs(i + 1, j, startColor)
      dfs(i - 1, j, startColor)
      dfs(i, j + 1, startColor)
      dfs(i, j - 1, startColor)

      # If this cell is already on the boarder, it must be painted later.
      if i == 0 or i == len(grid) - 1 or j == 0 or j == len(grid[0]) - 1:
        return

      if (abs(grid[i + 1][j]) == startColor and
          abs(grid[i - 1][j]) == startColor and
          abs(grid[i][j + 1]) == startColor and
              abs(grid[i][j - 1]) == startColor):
        grid[i][j] = startColor

    dfs(r0, c0, grid[r0][c0])

    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        if num < 0:
          grid[i][j] = color

    return grid
