class Solution:
  def smallestNumber(self, n: int) -> str:
    if n <= 9:
      return str(n)

    ans = []

    for divisor in range(9, 1, -1):
      while n % divisor == 0:
        ans.append(str(divisor))
        n //= divisor

    return '-1' if n > 1 else ''.join(reversed(ans))
