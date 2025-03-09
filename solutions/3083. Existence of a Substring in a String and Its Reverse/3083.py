class Solution:
  def isSubstringPresent(self, s: str) -> bool:
    return any(s[i:i + 2] in s[::-1] for i in range(len(s) - 1))
