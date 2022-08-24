class Solution:
  def isHappy(self, n: int) -> bool:
    def squaredSum(n: int) -> bool:
      sum = 0

      while n:
        sum += pow(n % 10, 2)
        n //= 10

      return sum

    slow = squaredSum(n)
    fast = squaredSum(squaredSum(n))

    while slow != fast:
      slow = squaredSum(slow)
      fast = squaredSum(squaredSum(fast))

    return slow == 1
