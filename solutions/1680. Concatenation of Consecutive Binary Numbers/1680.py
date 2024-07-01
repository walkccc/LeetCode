class Solution:
  def concatenatedBinary(self, n: int) -> int:
    kMod = 1_000_000_007
    ans = 0

    def numberOfBits(n: int) -> int:
      return int(math.log2(n)) + 1

    for i in range(1, n + 1):
      ans = ((ans << numberOfBits(i)) + i) % kMod

    return ans
