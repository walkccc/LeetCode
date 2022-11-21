class Solution:
  def isSameAfterReversals(self, num: int) -> bool:
    def getReversed(num: int) -> int:
      reversed = 0
      while num > 0:
        reversed = reversed * 10 + num % 10
        num //= 10
      return reversed

    reversed1 = getReversed(num)
    reversed2 = getReversed(reversed1)
    return reversed2 == num
