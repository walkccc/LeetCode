from sortedcontainers import SortedList


class Solution:
  def maxSumSubmatrix(self, matrix: list[list[int]], k: int) -> int:
    m = len(matrix)
    n = len(matrix[0])
    ans = -math.inf

    for baseCol in range(n):
      # sums[i] := sum(matrix[i][baseCol..j])
      sums = [0] * m
      for j in range(baseCol, n):
        for i in range(m):
          sums[i] += matrix[i][j]
        # Find the maximum sum <= k of all the subarrays.
        accumulate = SortedList([0])
        prefix = 0
        for summ in sums:
          prefix += summ
          it = accumulate.bisect_left(prefix - k)
          if it != len(accumulate):
            ans = max(ans, prefix - accumulate[it])
          accumulate.add(prefix)

    return ans
