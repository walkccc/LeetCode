class Solution:
  # Same as 76. Minimum Window Substring
  def shortestBeautifulSubstring(self, s: str, k: int) -> str:
    bestLeft = -1
    minLength = len(s) + 1
    ones = 0

    l = 0
    for r, c in enumerate(s):
      if c == '1':
        ones += 1
      while ones == k:
        if r - l + 1 < minLength:
          bestLeft = l
          minLength = r - l + 1
        elif r - l + 1 == minLength and s[l:l + minLength] < s[bestLeft:bestLeft + minLength]:
          bestLeft = l
        if s[l] == '1':
          ones -= 1
        l += 1

    return "" if bestLeft == -1 else s[bestLeft:bestLeft + minLength]
