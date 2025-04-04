class Solution:
  def minOperations(self, queries: list[list[int]]) -> int:
    return sum((self._getOperations(r) - self._getOperations(l - 1) + 1) // 2
               for l, r in queries)

  def _getOperations(self, n: int) -> int:
    """Returns the number of operations required for [1, n]."""
    res = 0
    ops = 0
    powerOfFour = 1
    while powerOfFour <= n:
      l = powerOfFour
      r = min(n, powerOfFour * 4 - 1)
      ops += 1
      res += (r - l + 1) * ops
      powerOfFour *= 4
    return res
