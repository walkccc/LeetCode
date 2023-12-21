class Solution:
  def countLargestGroup(self, n: int) -> int:
    count = [0] * (9 * 4 + 1)
    for i in range(1, n + 1):
      count[self._getDigitSum(i)] += 1
    return count.count(max(count))

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
