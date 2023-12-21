class Solution:
  def smallestFactorization(self, num: int) -> int:
    if num == 1:
      return 1

    ans = 0
    base = 1

    for i in range(9, 1, -1):
      while num % i == 0:
        num //= i
        ans = base * i + ans
        base *= 10

    return ans if num == 1 and ans < 2**31 - 1 else 0
