class Solution:
  def countBalls(self, lowLimit: int, highLimit: int) -> int:
    maxDigitSum = 9 * 5  # 99999
    ans = 0
    count = [0] * (maxDigitSum + 1)

    for num in range(lowLimit, highLimit + 1):
      digitSum = self._getDigitSum(num)
      count[digitSum] += 1
      ans = max(ans, count[digitSum])

    return ans

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
