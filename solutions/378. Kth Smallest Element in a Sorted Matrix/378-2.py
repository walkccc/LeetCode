class Solution:
  def kthSmallest(self, matrix: list[list[int]], k: int) -> int:
    def numsNoGreaterThan(m: int) -> int:
      count = 0
      j = len(matrix[0]) - 1
      # For each row, find the first index j s.t. row[j] <= m s.t. the number of
      # numbers <= m for this row will be j + 1.
      for row in matrix:
        while j >= 0 and row[j] > m:
          j -= 1
        count += j + 1
      return count

    l = matrix[0][0]
    r = matrix[-1][-1]
    return bisect.bisect_left(range(l, r), k, key=numsNoGreaterThan) + l
