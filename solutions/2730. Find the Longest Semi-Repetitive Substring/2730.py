class Solution:
  def longestSemiRepetitiveSubstring(self, s: str) -> int:
    ans = 1
    prevStart = 0
    start = 0

    for i in range(1, len(s)):
      if s[i] == s[i - 1]:
        if prevStart > 0:
          start = prevStart
        prevStart = i
      ans = max(ans, i - start + 1)

    return ans
