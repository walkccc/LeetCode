class Solution:
  def partitionString(self, s: str) -> int:
    ans = 1
    used = 0

    for c in s:
      i = string.ascii_lowercase.index(c)
      if used >> i & 1:
        used = 1 << i
        ans += 1
      else:
        used |= 1 << i

    return ans
