class Solution:
  def lastRemaining(self, n: int) -> int:
    return 1 if n == 1 else 2 * (1 + n // 2 - self.lastRemaining(n // 2))
