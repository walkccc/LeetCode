class Solution:
  def lengthOfLongestSubstring(self, s: str) -> int:
    ans = 0
    # The substring s[j + 1..i] has no repeating characters.
    j = -1
    # lastSeen[c] := the index of the last time c appeared
    lastSeen = {}

    for i, c in enumerate(s):
      # Update j to lastSeen[c], so the window must start from j + 1.
      j = max(j, lastSeen.get(c, -1))
      ans = max(ans, i - j)
      lastSeen[c] = i

    return ans
