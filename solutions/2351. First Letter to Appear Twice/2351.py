class Solution:
  def repeatedCharacter(self, s: str) -> str:
    seen = [False] * 26

    for c in s:
      if seen[string.ascii_lowercase.index(c)]:
        return c
      seen[string.ascii_lowercase.index(c)] = True
