class Solution:
  def getMoneyAmount(self, n: int) -> int:
    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """Returns the minimum money you need to guarantee a win of picking i..j.
      """
      if i >= j:
        return 0
      return min(max(dp(i, k - 1), dp(k + 1, j)) + k
                 for k in range(i, j + 1))

    return dp(1, n)
