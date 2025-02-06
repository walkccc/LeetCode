class Solution:
  def modifiedMatrix(self, matrix: list[list[int]]) -> list[list[int]]:
    m = len(matrix)
    n = len(matrix[0])
    ans = matrix.copy()

    for j in range(n):
      mx = max(matrix[i][j] for i in range(m))
      for i in range(m):
        if matrix[i][j] == -1:
          ans[i][j] = mx

    return ans
