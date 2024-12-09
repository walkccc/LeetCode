class Solution:
  def maximumValue(self, strs: list[str]) -> int:
    return max(len(s) if any(c.isalpha() for c in s) else int(s)
               for s in strs)
