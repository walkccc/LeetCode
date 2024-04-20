class Solution:
  def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
    m = len(grid)
    n = len(grid[0])
    ans = [[0] * n for _ in range(m)]

    def fillInDiagonal(i: int, j: int) -> None:
      topLeft = set()
      bottomRight = set()

      # Fill in the diagonal from the top-left to the bottom-right.
      while i < len(grid) and j < len(grid[0]):
        ans[i][j] = len(topLeft)
        # Post-addition, so this information can be utilized in subsequent cells.
        topLeft.add(grid[i][j])
        i += 1
        j += 1

      i -= 1
      j -= 1

      # Fill in the diagonal from the bottom-right to the top-left.
      while i >= 0 and j >= 0:
        ans[i][j] = abs(ans[i][j] - len(bottomRight))
        # Post-addition, so this information can be utilized in subsequent cells.
        bottomRight.add(grid[i][j])
        i -= 1
        j -= 1

    for i in range(m):
      fillInDiagonal(i, 0)

    for j in range(1, n):
      fillInDiagonal(0, j)

    return ans
