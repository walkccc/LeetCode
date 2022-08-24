class Solution:
  def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
    # dp(i, k) := max value of picking k coins from piles[i:]
    @functools.lru_cache(None)
    def dp(i: int, k: int) -> int:
      if i == len(piles) or k == 0:
        return 0

      ans = dp(i + 1, k)  # pick 0 coins from current pile
      val = 0  # coins picked from current pile

      # try to pick 1, 2, ..., k coins from current pile
      for j in range(min(len(piles[i]), k)):
        val += piles[i][j]
        ans = max(ans, val + dp(i + 1, k - j - 1))

      return ans

    return dp(0, k)
