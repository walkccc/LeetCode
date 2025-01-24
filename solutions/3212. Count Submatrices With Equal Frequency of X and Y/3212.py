class Solution:
  def numberOfSubmatrices(self, grid: list[list[str]]) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = 0
    # x[i][j] := the number of 'X' in grid[0..i)[0..j)
    x = [[0] * (n + 1) for _ in range(m + 1)]
    # y[i][j] := the number of 'Y' in grid[0..i)[0..j)
    y = [[0] * (n + 1) for _ in range(m + 1)]

    for i, row in enumerate(grid):
      for j, cell in enumerate(row):
        x[i + 1][j + 1] = (cell == 'X') + x[i][j + 1] + x[i + 1][j] - x[i][j]
        y[i + 1][j + 1] = (cell == 'Y') + y[i][j + 1] + y[i + 1][j] - y[i][j]
        if x[i + 1][j + 1] > 0 and x[i + 1][j + 1] == y[i + 1][j + 1]:
          ans += 1

    return ans
