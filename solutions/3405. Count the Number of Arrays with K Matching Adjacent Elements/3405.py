class Solution:
  def countGoodArrays(self, n: int, m: int, k: int) -> int:
    kMod = 1_000_000_007
    return m * pow(m - 1, n - k - 1, kMod) * math.comb(n - 1, k) % kMod
