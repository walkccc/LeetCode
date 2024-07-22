class Solution:
  def countNumbersWithUniqueDigits(self, n: int) -> int:
    if n == 0:
      return 1

    ans = 10
    uniqueDigits = 9
    availableNum = 9

    while n > 1 and availableNum > 0:
      uniqueDigits *= availableNum
      ans += uniqueDigits
      n -= 1
      availableNum -= 1

    return ans
