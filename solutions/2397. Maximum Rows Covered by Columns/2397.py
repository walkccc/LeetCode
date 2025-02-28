class Solution:
  def maximumRows(self, matrix: list[list[int]], numSelect: int) -> int:
    ans = 0

    def dfs(colIndex: int, leftColsCount: int, mask: int):
      nonlocal ans
      if leftColsCount == 0:
        ans = max(ans, self._getAllZerosRowCount(matrix, mask))
        return

      if colIndex == len(matrix[0]):
        return

      # Choose this column.
      dfs(colIndex + 1, leftColsCount - 1, mask | 1 << colIndex)
      # Don't choose this column.
      dfs(colIndex + 1, leftColsCount, mask)

    dfs(0, numSelect, 0)
    return ans

  def _getAllZerosRowCount(self, matrix: list[list[int]], mask: int) -> int:
    count = 0
    for row in matrix:
      isAllZeros = True
      for i, num in enumerate(row):
        if num == 1 and (mask >> i & 1) == 0:
          isAllZeros = False
          break
      if isAllZeros:
        count += 1
    return count
