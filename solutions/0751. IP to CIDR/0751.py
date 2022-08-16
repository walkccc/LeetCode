class Solution:
  def ipToCIDR(self, ip: str, n: int) -> List[str]:
    ans = []
    num = self._getNum(ip.split('.'))

    while n > 0:
      lowbit = num & -num
      count = self._maxLow(n) if lowbit == 0 else self._firstFit(lowbit, n)
      ans.append(self._getCIDR(num, self._getPrefix(count)))
      n -= count
      num += count

    return ans

  def _getNum(self, x: List[str]) -> int:
    num = 0
    for i in range(4):
      num = num * 256 + int(x[i])
    return num

  # return max i s.t. 2^i < n
  def _maxLow(self, n: int) -> Optional[int]:
    for i in range(32):
      if 1 << i + 1 > n:
        return 1 << i

  def _firstFit(self, lowbit: int, n: int) -> int:
    while lowbit > n:
      lowbit >>= 1
    return lowbit

  def _getCIDR(self, num: int, prefix: int) -> str:
    d = num & 255
    num >>= 8
    c = num & 255
    num >>= 8
    b = num & 255
    num >>= 8
    a = num & 255
    return '.'.join([str(s) for s in [a, b, c, d]]) + '/' + str(prefix)

  # e.g. count = 8 = 2^3 . prefix = 32 - 3 = 29
  #      count = 1 = 2^0 . prefix = 32 - 0 = 32
  def _getPrefix(self, count: int) -> Optional[int]:
    for i in range(32):
      if count == 1 << i:
        return 32 - i
