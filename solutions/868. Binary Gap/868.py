class Solution:
  def binaryGap(self, n: int) -> int:
    ans = 0
    d = -32  # the distance between any two 1s

    while n:
      if n % 2 == 1:
        ans = max(ans, d)
        d = 0
      n //= 2
      d += 1

    return ans
