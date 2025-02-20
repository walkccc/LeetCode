class Solution:
  def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
    if not matrix:
      return False

    m = len(matrix)
    n = len(matrix[0])
    l = 0
    r = m * n

    while l < r:
      mid = (l + r) // 2
      i = mid // n
      j = mid % n
      if matrix[i][j] == target:
        return True
      if matrix[i][j] < target:
        l = mid + 1
      else:
        r = mid

    return False
