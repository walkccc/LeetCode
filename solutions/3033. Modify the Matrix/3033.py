class Solution:
  def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
    m = len(matrix)
    n = len(matrix[0])
    ans = matrix.copy()

    for j in range(n):
      maxi = max(matrix[i][j] for i in range(m))
      for i in range(m):
        if matrix[i][j] == -1:
          ans[i][j] = maxi

    return ans
