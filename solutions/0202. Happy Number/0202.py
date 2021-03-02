class Solution:
  def isHappy(self, n: int) -> bool:
    def helper(n: int) -> bool:
      sum = 0

      while n:
        sum += pow(n % 10, 2)
        n //= 10

      return sum

    slow = helper(n)
    fast = helper(helper(n))

    while slow != fast:
      slow = helper(slow)
      fast = helper(helper(fast))

    return slow == 1
