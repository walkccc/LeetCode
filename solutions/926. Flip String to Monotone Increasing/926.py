class Solution:
  def minFlipsMonoIncr(self, s: str) -> int:
    # the number of characters to be flilpped to make the substring so far
    # monotone increasing
    dp = 0
    count1 = 0

    for c in s:
      if c == '0':
        # 1. Flip '0'.
        # 2. Keep '0' and flip all the previous 1s.
        dp = min(dp + 1, count1)
      else:
        count1 += 1

    return dp
