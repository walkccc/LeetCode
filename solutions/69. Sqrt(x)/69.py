class Solution:
  def mySqrt(self, x: int) -> int:
    return bisect.bisect_right(range(x + 1), x,
                               key=lambda m: m * m) - 1
