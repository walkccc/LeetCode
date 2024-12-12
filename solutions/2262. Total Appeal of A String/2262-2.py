class Solution:
  def appealSum(self, s: str) -> int:
    ans = 0
    lastSeen = {}

    for i, c in enumerate(s):
      ans += (i - lastSeen.get(c, -1)) * (len(s) - i)
      lastSeen[c] = i

    return ans
