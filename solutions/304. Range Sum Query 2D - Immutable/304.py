class NumMatrix:
  def __init__(self, matrix: list[list[int]]):
    if not matrix:
      return

    m = len(matrix)
    n = len(matrix[0])
    # prefix[i][j] := the sum of matrix[0..i)[0..j)
    self.prefix = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m):
      for j in range(n):
        self.prefix[i + 1][j + 1] = (matrix[i][j] + self.prefix[i][j + 1] +
                                     self.prefix[i + 1][j] - self.prefix[i][j])

  def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
    return (self.prefix[row2 + 1][col2 + 1] - self.prefix[row1][col2 + 1] -
            self.prefix[row2 + 1][col1] + self.prefix[row1][col1])
