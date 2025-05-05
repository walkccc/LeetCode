class Solution:
  def multiply(self, mat1: list[list[int]],
               mat2: list[list[int]]) -> list[list[int]]:
    m = len(mat1)
    n = len(mat2)
    l = len(mat2[0])
    ans = [[0] * l for _ in range(m)]

    for i in range(m):
      for j in range(l):
        for k in range(n):
          ans[i][j] += mat1[i][k] * mat2[k][j]

    return ans
