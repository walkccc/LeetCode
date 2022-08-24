class Solution:
  def binaryGap(self, n: int) -> int:
    ans = 0
    d = -32  # distance between any two 1's, initialized to a reasonable small value

    while n:
      if n & 1:
        ans = max(ans, d)
        d = 0
      n //= 2
      d += 1

    return ans
