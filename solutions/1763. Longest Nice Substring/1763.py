class Solution:
  def longestNiceSubstring(self, s: str) -> str:
    if len(s) < 2:
      return ''

    seen = set(s)

    for i, c in enumerate(s):
      # If both upper and lower case letters exists in the string, keep moving,
      # else take the erroneous character as a partition and check for its left
      # and right parts to be nice strings.
      if c.swapcase() not in seen:
        prefix = self.longestNiceSubstring(s[:i])
        suffix = self.longestNiceSubstring(s[i + 1:])
        return max(prefix, suffix, key=len)

    return s
