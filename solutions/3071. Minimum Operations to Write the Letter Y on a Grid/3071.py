class Solution:
  def minimumOperationsToWriteY(self, grid: list[list[int]]) -> int:
    n = len(grid)
    mid = n // 2

    def getOperations(a: int, b: int) -> int:
      """Returns the number of operations to turn Y into a and non-Y into b."""
      operations = 0
      for i, row in enumerate(grid):
        for j, num in enumerate(row):
          # For the 'Y' pattern, before the midpoint, check the diagonal and
          # anti-diagonal. After the midpoint, check the middle column.
          if (i < mid and (i == j or i + j == n - 1)) or i >= mid and j == mid:
            if num != a:
              operations += 1
          elif num != b:
            operations += 1
      return operations

    return min(getOperations(0, 1), getOperations(0, 2),
               getOperations(1, 0), getOperations(1, 2),
               getOperations(2, 0), getOperations(2, 1))
