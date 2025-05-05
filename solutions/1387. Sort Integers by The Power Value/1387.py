class Solution:
  def getKth(self, lo: int, hi: int, k: int) -> int:
    return sorted([(self._getPow(i), i) for i in range(lo, hi + 1)])[k - 1][1]

  def _getPow(self, n: int) -> int:
    if n == 1:
      return 0
    if n % 2 == 0:
      return 1 + self._getPow(n // 2)
    return 1 + self._getPow(n * 3 + 1)
