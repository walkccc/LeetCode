class Solution:
  # Same as 3256. Maximum Value Sum by Placing Three Rooks I
  def maximumValueSum(self, board: list[list[int]]) -> int:
    rows = [heapq.nlargest(3, [(val, i, j)
            for j, val in enumerate(row)])
            for i, row in enumerate(board)]
    cols = [heapq.nlargest(3, [(val, i, j)
            for i, val in enumerate(col)])
            for j, col in enumerate(zip(*board))]
    topNine = heapq.nlargest(9,
                             set(itertools.chain(*rows)) &
                             set(itertools.chain(*cols)))
    return max(
        (val1 + val2 + val3 for
         (val1, i1, j1),
         (val2, i2, j2),
         (val3, i3, j3) in (itertools.combinations(topNine, 3))
         if len({i1, i2, i3}) == 3 and len({j1, j2, j3}) == 3))
