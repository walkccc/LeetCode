class Solution:
  def minFlipsMonoIncr(self, s: str) -> int:
    # number of chars to be flilpped to make substring so far monotone increasing
    dp = 0
    count1 = 0

    for c in s:
      if c == '0':
        # 1. Flip '0'.
        # 2. Keep '0' and flip previous '1's.
        dp = min(dp + 1, count1)
      else:
        count1 += 1

    return dp
