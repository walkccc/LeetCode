class Solution:
  @functools.lru_cache(None)
  def minDays(self, n: int) -> int:
    if n <= 1:
      return n
    return 1 + min(self.minDays(n // 3) + n % 3,
                   self.minDays(n // 2) + n % 2)
