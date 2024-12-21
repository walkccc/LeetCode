class Solution:
  def setZeroes(self, matrix: list[list[int]]) -> None:
    m = len(matrix)
    n = len(matrix[0])
    shouldFillFirstRow = 0 in matrix[0]
    shouldFillFirstCol = 0 in list(zip(*matrix))[0]

    # Store the information in the first row and the first column.
    for i in range(1, m):
      for j in range(1, n):
        if matrix[i][j] == 0:
          matrix[i][0] = 0
          matrix[0][j] = 0

    # Fill 0s for the matrix except the first row and the first column.
    for i in range(1, m):
      for j in range(1, n):
        if matrix[i][0] == 0 or matrix[0][j] == 0:
          matrix[i][j] = 0

    # Fill 0s for the first row if needed.
    if shouldFillFirstRow:
      matrix[0] = [0] * n

    # Fill 0s for the first column if needed.
    if shouldFillFirstCol:
      for row in matrix:
        row[0] = 0
