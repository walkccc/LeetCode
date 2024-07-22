class Solution:
  # Same as 1012. Numbers With Repeated Digits
  def countSpecialNumbers(self, n: int) -> int:
    s = str(n)

    @functools.lru_cache(None)
    def dp(i: int, used: int, isTight: bool) -> int:
      """
      Returns the number of special integers, considering the i-th digit, where
      `used` is the bitmask of the used digits, and `isTight` indicates if the
      current digit is tightly bound.
      """
      if i == len(s):
        return 1

      res = 0

      maxDigit = int(s[i]) if isTight else 9
      for d in range(maxDigit + 1):
        # `d` is used.
        if used >> d & 1:
          continue
        # Use `d` now.
        nextIsTight = isTight and (d == maxDigit)
        if used == 0 and d == 0:  # Don't count leading 0s as used.
          res += dp(i + 1, used, nextIsTight)
        else:
          res += dp(i + 1, used | 1 << d, nextIsTight)

      return res

    return dp(0, 0, True) - 1  # - 0
