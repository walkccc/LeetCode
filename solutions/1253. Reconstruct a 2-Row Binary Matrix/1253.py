class Solution:
  def reconstructMatrix(self, upper: int, lower: int, colsum: list[int]) -> list[list[int]]:
    if upper + lower != sum(colsum):
      return []
    if min(upper, lower) < colsum.count(2):
      return []

    ans = [[0] * len(colsum) for _ in range(2)]

    for j, c in enumerate(colsum):
      if c == 2:
        ans[0][j] = 1
        ans[1][j] = 1
        upper -= 1
        lower -= 1

    for j, c in enumerate(colsum):
      if c == 1 and upper > 0:
        ans[0][j] = 1
        c -= 1
        upper -= 1
      if c == 1 and lower > 0:
        ans[1][j] = 1
        lower -= 1

    return ans
