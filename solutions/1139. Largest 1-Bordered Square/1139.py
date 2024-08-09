class Solution:
  def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])

    # leftOnes[i][j] := consecutive 1s in the left of grid[i][j]
    leftOnes = [[0] * n for _ in range(m)]
    # topOnes[i][j] := consecutive 1s in the top of grid[i][j]
    topOnes = [[0] * n for _ in range(m)]

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1:
          leftOnes[i][j] = 1 if j == 0 else 1 + leftOnes[i][j - 1]
          topOnes[i][j] = 1 if i == 0 else 1 + topOnes[i - 1][j]

    for sz in range(min(m, n), 0, -1):
      for i in range(m - sz + 1):
        for j in range(n - sz + 1):
          x = i + sz - 1
          y = j + sz - 1
          # If grid[i..x][j..y] has all 1s on its border.
          if min(leftOnes[i][y], leftOnes[x][y], topOnes[x][j], topOnes[x][y]) >= sz:
            return sz * sz

    return 0
