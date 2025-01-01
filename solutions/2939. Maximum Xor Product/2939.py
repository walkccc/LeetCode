class Solution:
  def maximumXorProduct(self, a: int, b: int, n: int) -> int:
    kMod = 1_000_000_007
    for bit in (2**i for i in range(n)):
      # Pick a bit if it makes min(a, b) larger.
      if a * b < (a ^ bit) * (b ^ bit):
        a ^= bit
        b ^= bit
    return a * b % kMod
