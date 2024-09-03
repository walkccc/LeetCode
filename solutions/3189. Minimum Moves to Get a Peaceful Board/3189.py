class Solution:
  def minMoves(self, rooks: list[list[int]]) -> int:
    n = len(rooks)
    sortedByRow = sorted(rooks, key=lambda x: x[0])
    sortedByCol = sorted(rooks, key=lambda x: x[1])
    return (sum(abs(i - row) for (i, _), row in zip(sortedByRow, range(n))) +
            sum(abs(j - col) for (_, j), col in zip(sortedByCol, range(n))))
