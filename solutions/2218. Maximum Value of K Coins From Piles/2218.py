class Solution:
  def maxValueOfCoins(self, piles: list[list[int]], k: int) -> int:
    @functools.lru_cache(None)
    def dp(i: int, k: int) -> int:
      """Returns the maximum value of picking k coins from piles[i..n)."""
      if i == len(piles) or k == 0:
        return 0

      # Pick no coins from the current pile.
      res = dp(i + 1, k)
      val = 0  # the coins picked from the current pile

      # Try to pick 1, 2, ..., k coins from the current pile.
      for j in range(min(len(piles[i]), k)):
        val += piles[i][j]
        res = max(res, val + dp(i + 1, k - j - 1))

      return res

    return dp(0, k)
