class Solution:
  def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
    digitSum = self._getDigitSum(x)
    return digitSum if x % digitSum == 0 else -1

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
