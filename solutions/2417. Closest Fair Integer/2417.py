class Solution:
  def closestFair(self, n: int) -> int:
    digitsCount = len(str(n))
    return self._getOddDigits(digitsCount) if digitsCount & 1 else self._getEvenDigits(n)

  def _getOddDigits(self, digitsCount: int) -> int:
    zeros = (digitsCount + 1) // 2
    ones = (digitsCount - 1) // 2
    return int('1' + '0' * zeros + '1' * ones)

  def _getEvenDigits(self, n: int) -> int:
    digitsCount = len(str(n))
    maxNum = int('1' + '0' * digitsCount)
    for num in range(n, maxNum):
      if self._isValidNum(num):
        return num
    return self._getOddDigits(digitsCount + 1)

  def _isValidNum(self, num: int) -> bool:
    count = 0
    for c in str(num):
      count += -1 if ord(c) - ord('0') & 1 else 1
    return count == 0
