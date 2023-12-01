class Solution:
  def countEven(self, num: int) -> int:
    return (num - self.sumOfDigit(num) % 2) // 2

  def sumOfDigit(self, num: int) -> int:
    summ = 0
    while num:
      summ += num % 10
      num //= 10
    return summ
