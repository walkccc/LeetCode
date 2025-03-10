class Solution:
  def isPowerOfTwo(self, n: int) -> bool:
    return n >= 0 and n.bit_count() == 1
