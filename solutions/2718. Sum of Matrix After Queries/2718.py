class Solution:
  def matrixSumQueries(self, n: int, queries: list[list[int]]) -> int:
    ans = 0
    # seen[0] := row, seen[1] := col
    seen = [[False] * n for _ in range(2)]
    # notSet[0] = row, notSet[1] := col
    notSet = [n] * 2

    # Late queries dominate.
    for type, index, val in reversed(queries):
      if not seen[type][index]:
        ans += val * notSet[type ^ 1]
        seen[type][index] = True
        notSet[type] -= 1

    return ans
