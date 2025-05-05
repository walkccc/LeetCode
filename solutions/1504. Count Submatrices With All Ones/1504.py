class Solution:
  def numSubmat(self, mat: list[list[int]]) -> int:
    m = len(mat)
    n = len(mat[0])
    ans = 0

    for baseRow in range(m):
      row = [1] * n
      for i in range(baseRow, m):
        for j in range(n):
          row[j] &= mat[i][j]
        ans += self._count(row)

    return ans

  def _count(self, row: list[int]) -> int:
    res = 0
    length = 0
    for num in row:
      length = 0 if num == 0 else length + 1
      res += length
    return res
