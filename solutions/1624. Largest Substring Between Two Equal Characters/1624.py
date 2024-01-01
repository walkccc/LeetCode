class Solution:
  def maxLengthBetweenEqualCharacters(self, s: str) -> int:
    ans = -1
    lastSeen = {}

    for i, c in enumerate(s):
      if c not in lastSeen:
        lastSeen[c] = i
      else:
        ans = max(ans, i - lastSeen[c] - 1)

    return ans
