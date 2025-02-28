class Solution:
  def numberOfCuts(self, n: int) -> int:
    if n == 1:
      return 0
    return n // 2 if n % 2 == 0 else n
