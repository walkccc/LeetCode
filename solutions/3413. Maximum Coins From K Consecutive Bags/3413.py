class Solution:
  def maximumCoins(self, coins: list[list[int]], k: int) -> int:
    return max(self._slide(coins, k),
               self._slide([[-r, -l, c] for l, r, c in coins], k))

  def _slide(self, coins: list[list[int]], k: int) -> int:
    coins.sort()
    res = 0
    windowSum = 0
    j = 0
    for li, ri, ci in coins:  # Consider the number line [li..li + k).
      rightBoundary = li + k

      # [lj, rj] is fully in [li..li + k).
      while j + 1 < len(coins) and coins[j + 1][0] < rightBoundary:
        lj, rj, cj = coins[j]
        windowSum += (rj - lj + 1) * cj
        j += 1

      # [lj, rj] may be partially in [l..l + k).
      last = 0
      if j < len(coins) and coins[j][0] < rightBoundary:
        lj, rj, cj = coins[j]
        last = (min(rightBoundary - 1, rj) - lj + 1) * cj

      res = max(res, windowSum + last)
      windowSum -= (ri - li + 1) * ci
    return res
