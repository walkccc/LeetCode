class Solution:
  def countKReducibleNumbers(self, s: str, k: int) -> int:
    MOD = 1_000_000_007
    ops = self._getOps(s)

    @functools.lru_cache(None)
    def dp(i: int, setBits: int, tight: bool) -> int:
      """
      Returns the number of positive integers less than n that are k-reducible,
      considering the i-th digit, where `setBits` is the number of set bits in
      the current number, and `tight` indicates if the current digit is
      tightly bound.
      """
      if i == len(s):
        return int(ops[setBits] < k and not tight)

      res = 0
      maxDigit = int(s[i]) if tight else 1

      for d in range(maxDigit + 1):
        nextTight = tight and (d == maxDigit)
        res += dp(i + 1, setBits + d, nextTight)
        res %= MOD
      return res

    return dp(0, 0, True) - 1  # - 0

  def _getOps(self, s: str) -> int:
    """Returns the number of operations to reduce a number to 0."""
    ops = [0] * (len(s) + 1)
    for num in range(2, len(s) + 1):
      ops[num] = 1 + ops[num.bit_count()]
    return ops
