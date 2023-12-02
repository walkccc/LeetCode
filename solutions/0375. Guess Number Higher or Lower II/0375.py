class Solution:
  def getMoneyAmount(self, n: int) -> int:
    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """Returns the minimum money you need to guarantee a win of picking i..j.
      """
      if i >= j:
        return 0

      ans = math.inf

      for k in range(i, j + 1):
        ans = min(ans, max(dp(i, k - 1), dp(k + 1, j)) + k)

      return ans

    return dp(1, n)
