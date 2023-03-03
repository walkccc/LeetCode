class Solution:
  def closestFair(self, n: int) -> int:
    digitsCount = len(str(n))
    return self._getOddDigits(digitsCount) if digitsCount & 1 else self._getEvenDigits(n)

  def _getOddDigits(self, digitsCount: int) -> int:
    zerosCount = (digitsCount + 1) // 2
    onesCount = (digitsCount - 1) // 2
    return '1' + '0' * zerosCount + '1' * onesCount

  def _getEvenDigits(self, n: int) -> int:
    digitsCount = len(str(n))
    maxNum = int('1' + '0' * digitsCount)
    for num in range(n, maxNum):
      if self._isValidNum(num):
        return num
    return self._getOddDigits(digitsCount + 1)

  def _isValidNum(self, num: int) -> bool:
    count = 0
    s = str(num)
    for c in s:
      count += -1 if ord(c) - ord('0') & 1 else 1
    return count == 0
