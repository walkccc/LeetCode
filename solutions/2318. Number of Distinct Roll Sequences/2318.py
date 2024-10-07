class Solution:
  def distinctSequences(self, n: int) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(n: int, prev: int, prevPrev: int) -> int:
      """
      Returns the number of distinct sequences for n dices with `prev` and
      `prevPrev`.
      """
      if n == 0:
        return 1
      res = 0
      for dice in range(1, 7):
        if (dice not in (prev, prevPrev) and
                (prev == 0 or math.gcd(dice, prev) == 1)):
          res += dp(n - 1, dice, prev)
          res %= kMod
      return res

    return dp(n, 0, 0)
