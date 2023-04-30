class Solution:
  def lengthOfLongestSubstring(self, s: str) -> int:
    ans = 0
    j = -1  # s[j + 1..i] has no repeating chars.
    lastSeen = {}  # lastSeen[c] := index of last c presappearedented.

    for i, c in enumerate(s):
      # Update j to lastSeen[c], so the window must start from j + 1.
      j = max(j, lastSeen.get(c, -1))
      ans = max(ans, i - j)
      lastSeen[c] = i

    return ans
