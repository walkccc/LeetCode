class Solution:
  def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
    l = matrix[0][0]
    r = matrix[-1][-1]

    def numsNoGreaterThan(m: int) -> int:
      count = 0
      j = len(matrix[0]) - 1
      # for each row, find the first index j s.t. row[j] <= m
      # so numsNoGreaterThan m for this row will be j + 1
      for row in matrix:
        while j >= 0 and row[j] > m:
          j -= 1
        count += j + 1
      return count

    while l < r:
      m = (l + r) // 2
      if numsNoGreaterThan(m) >= k:
        r = m
      else:
        l = m + 1

    return l
