class Solution:
  def maxEqualRowsAfterFlips(self, matrix: list[list[int]]) -> int:
    patterns = [tuple(a ^ row[0] for a in row) for row in matrix]
    return max(Counter(patterns).values())
