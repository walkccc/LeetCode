class Solution:
  def largestMagicSquare(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    # prefixRow[i][j] := the sum of the first j numbers in the i-th row
    prefixRow = [[0] * (n + 1) for _ in range(m)]
    # prefixCol[i][j] := the sum of the first j numbers in the i-th column
    prefixCol = [[0] * (m + 1) for _ in range(n)]

    for i in range(m):
      for j in range(n):
        prefixRow[i][j + 1] = prefixRow[i][j] + grid[i][j]
        prefixCol[j][i + 1] = prefixCol[j][i] + grid[i][j]

    def isMagicSquare(i: int, j: int, k: int) -> bool:
      """Returns True if grid[i..i + k)[j..j + k) is a magic square."""
      diag, antiDiag = 0, 0
      for d in range(k):
        diag += grid[i + d][j + d]
        antiDiag += grid[i + d][j + k - 1 - d]
      if diag != antiDiag:
        return False
      for d in range(k):
        if self._getSum(prefixRow, i + d, j, j + k - 1) != diag:
          return False
        if self._getSum(prefixCol, j + d, i, i + k - 1) != diag:
          return False
      return True

    def containsMagicSquare(k: int) -> bool:
      """Returns True if the grid contains any magic square of size k x k."""
      for i in range(m - k + 1):
        for j in range(n - k + 1):
          if isMagicSquare(i, j, k):
            return True
      return False

    for k in range(min(m, n), 1, -1):
      if containsMagicSquare(k):
        return k

    return 1

  def _getSum(self, prefix: List[List[int]], i: int, l: int, r: int) -> int:
    """Returns sum(grid[i][l..r]) or sum(grid[l..r][i])."""
    return prefix[i][r + 1] - prefix[i][l]
