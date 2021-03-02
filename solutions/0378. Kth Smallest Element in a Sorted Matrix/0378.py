class Solution:
  def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
    l = matrix[0][0]
    r = matrix[-1][-1]

    while l < r:
      m = (l + r) >> 1
      count = 0
      for row in matrix:
        count += bisect.bisect(row, m)
      if count >= k:
        r = m
      else:
        l = m + 1

    return l
