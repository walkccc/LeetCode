class Solution:
  def getMoneyAmount(self, n: int) -> int:
    # dp(i, j) := min money you need to guarantee a win of picking i..j
    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      if i >= j:
        return 0

      ans = math.inf

      for k in range(i, j + 1):
        ans = min(ans, max(dp(i, k - 1), dp(k + 1, j)) + k)

      return ans

    return dp(1, n)
