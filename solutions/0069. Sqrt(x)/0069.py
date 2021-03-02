class Solution:
  def mySqrt(self, x: int) -> int:
    l = 1
    r = x + 1

    while l < r:
      m = (l + r) // 2
      if m * m > x:
        r = m
      else:
        l = m + 1

    # l: smallest number s.t. l * l > x
    return l - 1
