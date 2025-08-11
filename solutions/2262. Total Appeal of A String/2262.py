class Solution:
  def appealSum(self, s: str) -> int:
    ans = 0
    # the total appeal of all substrings ending in the index so far
    dp = 0
    lastSeen = {}

    for i, c in enumerate(s):
      #   the total appeal of all substrings ending in s[i]
      # = the total appeal of all substrings ending in s[i - 1]
      # + the number of substrings ending in s[i] that contain only this s[i]
      dp += i - lastSeen.get(c, -1)
      ans += dp
      lastSeen[c] = i

    return ans
