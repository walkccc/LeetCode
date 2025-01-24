class Solution:
  def countBlackBlocks(
      self,
      m: int,
      n: int,
      coordinates: list[list[int]],
  ) -> list[int]:
    ans = [0] * 5
    # count[i * n + j] := the number of black cells in
    # (i - 1, j - 1), (i - 1, j), (i, j - 1), (i, j)
    count = collections.Counter()

    for x, y in coordinates:
      for i in range(x, x + 2):
        for j in range(y, y + 2):
          # 2 x 2 submatrix with right-bottom conner being (i, j) contains the
          # current black cell (x, y).
          if 0 < i < m and 0 < j < n:
            count[(i, j)] += 1

    for freq in count.values():
      ans[freq] += 1

    ans[0] = (m - 1) * (n - 1) - sum(ans)
    return ans
