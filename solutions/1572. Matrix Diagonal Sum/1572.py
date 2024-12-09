class Solution:
  def diagonalSum(self, mat: list[list[int]]) -> int:
    n = len(mat)
    ans = 0

    for i in range(n):
      ans += mat[i][i]
      ans += mat[n - 1 - i][i]

    return ans if n % 2 == 0 else ans - mat[n // 2][n // 2]
