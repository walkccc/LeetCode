class Solution:
  def trailingZeroes(self, n: int) -> int:
    return 0 if n == 0 else n // 5 + self.trailingZeroes(n // 5)
