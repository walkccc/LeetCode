class Solution:
  def numberOfCuts(self, n: int) -> int:
    if n == 1:
      return 0
    return n if n & 1 else n // 2
