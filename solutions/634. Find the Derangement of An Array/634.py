class Solution:
  def findDerangement(self, n: int) -> int:
    MOD = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int) -> int:
      if i == 0:
        return 1
      if i == 1:
        return 0
      return (i - 1) * (dp(i - 1) + dp(i - 2)) % MOD

    return dp(n)
