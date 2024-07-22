class Solution:
  def isPowerOfFour(self, n: int) -> bool:
    # Why (4^n - 1) % 3 == 0?
    # (4^n - 1) = (2^n - 1)(2^n + 1) and 2^n - 1, 2^n, 2^n + 1 are
    # three consecutive numbers; among one of them, there must be a multiple
    # of 3, and that can't be 2^n, so it must be either 2^n - 1 or 2^n + 1.
    # Therefore, 4^n - 1 is a multiple of 3.
    return n > 0 and n.bit_count() == 1 and (n - 1) % 3 == 0
