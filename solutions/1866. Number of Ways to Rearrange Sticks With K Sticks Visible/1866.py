class Solution:
  @functools.lru_cache(None)
  def rearrangeSticks(self, n: int, k: int) -> int:
    if n == k:
      return 1
    if k == 0:
      return 0
    return (self.rearrangeSticks(n - 1, k - 1) +
            self.rearrangeSticks(n - 1, k) * (n - 1)) % self.kMod

  kMod = 1_000_000_007
