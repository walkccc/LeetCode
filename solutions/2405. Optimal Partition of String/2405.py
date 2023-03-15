class Solution:
  def partitionString(self, s: str) -> int:
    ans = 1
    usedMask = 0

    for c in s:
      i = ord(c) - ord('a')
      if usedMask >> i & 1:
        usedMask = 1 << i
        ans += 1
      else:
        usedMask |= 1 << i

    return ans
