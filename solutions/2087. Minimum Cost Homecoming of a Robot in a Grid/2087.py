class Solution:
  def minCost(
      self,
      startPos: list[int],
      homePos: list[int],
      rowCosts: list[int],
      colCosts: list[int],
  ) -> int:
    ans = 0
    i, j = startPos
    x, y = homePos

    while i != x:
      i += 1 if i < x else -1
      ans += rowCosts[i]

    while j != y:
      j += 1 if j < y else -1
      ans += colCosts[j]

    return ans
