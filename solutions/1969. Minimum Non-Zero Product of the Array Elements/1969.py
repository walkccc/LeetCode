class Solution:
  def minNonZeroProduct(self, p: int) -> int:
    kMod = 1_000_000_007
    # Can always turn [1..2^p - 1] to [1, 1, ..., 2^p - 2, 2^p - 2, 2^p - 1].
    n = 1 << p
    halfCount = n // 2 - 1
    return pow(n - 2, halfCount, kMod) * ((n - 1) % kMod) % kMod
