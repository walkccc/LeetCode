class Solution:
  def findNthDigit(self, n: int) -> int:
    def getDigit(num: int, pos: int, digitSize: int):
      if pos == 0:
        return num % 10
      for _ in range(digitSize - pos):
        num //= 10
      return num % 10

    digitSize = 1
    startNum = 1
    count = 9

    while digitSize * count < n:
      n -= digitSize * count
      digitSize += 1
      startNum *= 10
      count *= 10

    targetNum = startNum + (n - 1) // digitSize
    pos = n % digitSize

    return getDigit(targetNum, pos, digitSize)
