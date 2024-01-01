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

      ans = 0
      for dice in range(1, 7):
        if dice != prev and dice != prevPrev and \
                (prev == 0 or math.gcd(dice, prev) == 1):
          ans += dp(n - 1, dice, prev)
          ans %= kMod
      return ans

    return dp(n, 0, 0)
