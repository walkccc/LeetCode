class Solution:
  def minFlips(self, a: int, b: int, c: int) -> int:
    MAX_BIT = 30
    ans = 0

    for i in range(MAX_BIT):
      if c >> i & 1:
        ans += (a >> i & 1) == 0 and (b >> i & 1) == 0
      else:  # (c >> i & 1) == 0
        ans += (a >> i & 1) + (b >> i & 1)

    return ans
