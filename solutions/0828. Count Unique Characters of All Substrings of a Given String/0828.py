class Solution:
  def uniqueLetterString(self, s: str) -> int:
    ans = 0
    # Number of unique letters in all substrings ending at the index so far
    dp = 0
    lastCount = {}
    lastSeen = {}

    for i, c in enumerate(s):
      newCount = i - lastSeen.get(c, -1)
      # Minus the duplicates.
      dp -= lastCount.get(c, 0)
      # Add count of s[lastSeen[c] + 1..i], s[lastSeen[c] + 2..i], ..., s[i].
      dp += newCount
      lastCount[c] = newCount
      lastSeen[c] = i
      ans += dp

    return ans
