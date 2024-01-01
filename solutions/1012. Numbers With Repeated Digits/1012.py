class Solution:
  def numDupDigitsAtMostN(self, n: int) -> int:
    return n - self._countSpecialNumbers(n)

  def _countSpecialNumbers(self, n: int) -> int:
    s = str(n)

    @functools.lru_cache(None)
    def dp(i: int, usedMask: int, isTight: bool) -> int:
      """
      Returns the number of special integers with current digit i and `usedMask`
      j, where k is 0/1 tight constraint.
      """
      if i == len(s):
        return 1

      res = 0

      maxDigit = int(s[i]) if isTight else 9
      for d in range(maxDigit + 1):
        # `d` is used.
        if usedMask >> d & 1:
          continue
        # Use `d` now.
        nextIsTight = isTight and (d == maxDigit)
        if usedMask == 0 and d == 0:  # Don't count leading 0s as used.
          res += dp(i + 1, usedMask, nextIsTight)
        else:
          res += dp(i + 1, usedMask | 1 << d, nextIsTight)

      return res

    return dp(0, 0, True) - 1  # - 0
