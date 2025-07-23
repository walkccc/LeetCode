class Solution:
  def countSteppingNumbers(self, low: str, high: str) -> int:
    MOD = 1_000_000_007
    low = '0' * (len(high) - len(low)) + low

    @functools.lru_cache(None)
    def dp(
        i: int,
        prevDigit: int,
        isLeadingZero: bool,
        tight1: bool,
        tight2: bool,
    ) -> int:
      """
      Returns the number of valid integers, considering the i-th digit, where
      `prevDigit` is the previous digit, `tight1` indicates if the current
      digit is tightly bound for `low`, and `tight2` indicates if the current
      digit is tightly bound for `high`.
      """
      if i == len(high):
        return 1

      res = 0
      minDigit = int(low[i]) if tight1 else 0
      maxDigit = int(high[i]) if tight2 else 9

      for d in range(minDigit, maxDigit + 1):
        nextTight1 = tight1 and (d == minDigit)
        nextTight2 = tight2 and (d == maxDigit)
        if isLeadingZero:
          # Can place any digit in [minDigit, maxDigit].
          res += dp(i + 1, d, isLeadingZero and d ==
                    0, nextTight1, nextTight2)
        elif abs(d - prevDigit) == 1:
          res += dp(i + 1, d, False, nextTight1, nextTight2)
        res %= MOD

      return res

    return dp(0, -1, True, True, True)
