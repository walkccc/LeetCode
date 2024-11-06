class Solution:
  def hammingDistance(self, x: int, y: int) -> int:
    ans = 0

    while x > 0 or y > 0:
      ans += (x & 1) ^ (y & 1)
      x >>= 1
      y >>= 1

    return ans
