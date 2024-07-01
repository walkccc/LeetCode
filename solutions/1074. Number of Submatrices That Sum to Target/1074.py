class Solution:
  def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
    m = len(matrix)
    n = len(matrix[0])
    ans = 0

    # Transfer each row in the matrix to the prefix sum.
    for row in matrix:
      for i in range(1, n):
        row[i] += row[i - 1]

    for baseCol in range(n):
      for j in range(baseCol, n):
        prefixCount = collections.Counter({0: 1})
        summ = 0
        for i in range(m):
          if baseCol > 0:
            summ -= matrix[i][baseCol - 1]
          summ += matrix[i][j]
          ans += prefixCount[summ - target]
          prefixCount[summ] += 1

    return ans
