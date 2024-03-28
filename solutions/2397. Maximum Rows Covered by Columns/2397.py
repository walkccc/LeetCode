class Solution:
  def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
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

  def _getAllZerosRowCount(self, matrix: List[List[int]], mask: int) -> int:
    count = 0
    for row in matrix:
      isAllZeros = True
      for i, cell in enumerate(row):
        if cell == 1 and (mask >> i & 1) == 0:
          isAllZeros = False
          break
      if isAllZeros:
        count += 1
    return count
