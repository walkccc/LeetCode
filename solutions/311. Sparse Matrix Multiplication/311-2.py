class Solution:
  def multiply(self, mat1: list[list[int]],
               mat2: list[list[int]]) -> list[list[int]]:
    m = len(mat1)
    n = len(mat2)
    l = len(mat2[0])
    ans = [[0] * l for _ in range(m)]
    nonZeroColIndicesInMat2 = [
        [j for j, a in enumerate(row) if a]
        for row in mat2
    ]

    for i in range(m):
      for j, a in enumerate(mat1[i]):
        if a == 0:
          continue
        # mat1s j-th column matches mat2's j-th row
        for colIndex in nonZeroColIndicesInMat2[j]:
          ans[i][colIndex] += a * mat2[j][colIndex]

    return ans
