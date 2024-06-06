class Solution:
  def partitionString(self, s: str) -> int:
    ans = 1
    used = 0

    for c in s:
      i = ord(c) - ord('a')
      if used >> i & 1:
        used = 1 << i
        ans += 1
      else:
        used |= 1 << i

    return ans
