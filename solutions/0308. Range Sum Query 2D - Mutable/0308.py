class FenwickTree:
  def __init__(self, m: int, n: int):
    self.sums = [[0] * (n + 1) for _ in range(m + 1)]

  def update(self, row: int, col: int, delta: int) -> None:
    i = row
    while i < len(self.sums):
      j = col
      while j < len(self.sums[0]):
        self.sums[i][j] += delta
        j += j & -j
      i += i & -i

  def get(self, row: int, col: int) -> int:
    summ = 0
    i = row
    while i > 0:
      j = col
      while j > 0:
        summ += self.sums[i][j]
        j -= j & -j
      i -= i & -i
    return summ


class NumMatrix:
  def __init__(self, matrix: List[List[int]]):
    self.matrix = matrix
    self.tree = FenwickTree(len(matrix), len(matrix[0]))

    for i in range(len(matrix)):
      for j, val in enumerate(matrix[i]):
        self.tree.update(i + 1, j + 1, val)

  def update(self, row: int, col: int, val: int) -> None:
    self.tree.update(row + 1, col + 1, val - self.matrix[row][col])
    self.matrix[row][col] = val

  def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
    return self.tree.get(row2 + 1, col2 + 1) - self.tree.get(row1, col2 + 1) - \
        self.tree.get(row2 + 1, col1) + self.tree.get(row1, col1)
