class Solution:
  def repeatedCharacter(self, s: str) -> str:
    seen = [False] * 26

    for c in s:
      if seen[ord(c) - ord('a')]:
        return c
      seen[ord(c) - ord('a')] = True
