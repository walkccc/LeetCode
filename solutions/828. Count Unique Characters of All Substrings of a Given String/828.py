class Solution:
  def uniqueLetterString(self, s: str) -> int:
    ans = 0
    # the number of unique letters in all the substrings ending in the index so
    # far
    dp = 0
    lastCount = {}
    lastSeen = {}

    for i, c in enumerate(s):
      newCount = i - lastSeen.get(c, -1)
      # Substract the duplicates.
      dp -= lastCount.get(c, 0)
      # Add count of s[lastSeen[c] + 1..i], s[lastSeen[c] + 2..i], ..., s[i].
      dp += newCount
      lastCount[c] = newCount
      lastSeen[c] = i
      ans += dp

    return ans
