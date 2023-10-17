class Solution:
  def minOperations(self, n: int) -> int:
    # The strategy is that when the end of n is
    #   - consecutive 1s, add 1 (2^0).
    #   - single 1, minus 1 (2^0).
    #   - 0, minus 2^k to omit the last 1. Equivalently, n >> 1.
    #
    # E.g.
    #
    #         n = (101)2
    # n -= 2^0 . (100)2
    # n -= 2^2 . (0)2
    #         n = (1011)2
    # n += 2^0 . (1100)2
    # n -= 2^2 . (1000)2
    # n -= 2^3 . (0)2
    ans = 0

    while n > 0:
      if (n & 3) == 3:
        n += 1
        ans += 1
      elif (n & 1) == 1:
        n -= 1
        ans += 1
      else:
        n >>= 1

    return ans
