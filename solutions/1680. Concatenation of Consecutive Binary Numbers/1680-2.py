class Solution:
  def concatenatedBinary(self, n: int) -> int:
    kMod = 1_000_000_007
    ans = 0
    numberOfBits = 0

    for i in range(1, n + 1):
      if i.bit_count() == 1:
        numberOfBits += 1
      ans = ((ans << numberOfBits) + i) % kMod

    return ans
