class Solution:
  def getLucky(self, s: str, k: int) -> int:
    ans = self._convert(s)
    for _ in range(k):
      ans = self._getDigitSum(ans)
    return ans

  def _convert(self, s: str) -> int:
    return int(''.join(str(ord(c) - ord('a') + 1) for c in s))

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
