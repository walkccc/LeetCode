class Solution:
  def countEven(self, num: int) -> int:
    return (num - self._getDigitSum(num) % 2) // 2

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
