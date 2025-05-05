class Solution:
  def maxProduct(self, n: int) -> int:
    s = sorted(str(n))
    return int(s[-1]) * int(s[-2])
