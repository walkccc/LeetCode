class Solution:
  def possibleToStamp(self, grid: List[List[int]], stampHeight: int, stampWidth: int) -> bool:
    m = len(grid)
    n = len(grid[0])
    # A[i][j] := the number of 1s in grid[0..i)[0..j)
    A = [[0] * (n + 1) for _ in range(m + 1)]
    # B[i][j] := the number of ways to stamp the submatrix in [0..i)[0..j)
    B = [[0] * (n + 1) for _ in range(m + 1)]
    # fit[i][j] := true if the stamps can fit with the right-bottom at (i, j)
    fit = [[False] * n for _ in range(m)]

    for i in range(m):
      for j in range(n):
        A[i + 1][j + 1] = A[i + 1][j] + A[i][j + 1] - A[i][j] + grid[i][j]
        if i + 1 >= stampHeight and j + 1 >= stampWidth:
          x = i - stampHeight + 1
          y = j - stampWidth + 1
          if A[i + 1][j + 1] - A[x][j + 1] - A[i + 1][y] + A[x][y] == 0:
            fit[i][j] = True

    for i in range(m):
      for j in range(n):
        B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + fit[i][j]

    for i in range(m):
      for j in range(n):
        if not grid[i][j]:
          x = min(i + stampHeight, m)
          y = min(j + stampWidth, n)
          if B[x][y] - B[i][y] - B[x][j] + B[i][j] == 0:
            return False

    return True
