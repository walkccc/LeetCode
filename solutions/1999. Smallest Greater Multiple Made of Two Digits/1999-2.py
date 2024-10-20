class Solution:
  def findInteger(self, k: int, digit1: int, digit2: int) -> int:
    def dfs(x: int) -> int:
      if x > 2**31 - 1:
        return -1
      if x > k and x % k == 0:
        return x
      # Skip if digit1/digit2 and x are zero.
      a = -1 if x + digit1 == 0 else dfs(x * 10 + digit1)
      b = -1 if x + digit2 == 0 else dfs(x * 10 + digit2)
      if a == -1:
        return b
      if b == -1:
        return a
      return min(a, b)

    return dfs(0)
