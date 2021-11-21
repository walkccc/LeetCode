class Solution:
  def isUgly(self, num: int) -> bool:
    if num == 0:
      return False

    for prime in 2, 3, 5:
      while num % prime == 0:
        num //= prime

    return num == 1
