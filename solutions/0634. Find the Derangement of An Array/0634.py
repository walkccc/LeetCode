class Solution:
  def findDerangement(self, n: int) -> int:
    kMod = int(1e9) + 7

    @lru_cache(None)
    def dp(i: int) -> int:
      if i == 0:
        return 1
      if i == 1:
        return 0
      return (i - 1) * (dp(i - 1) + dp(i - 2)) % kMod

    return dp(n)
