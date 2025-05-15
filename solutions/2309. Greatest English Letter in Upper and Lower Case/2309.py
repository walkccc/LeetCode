class Solution:
  def greatestLetter(self, s: str) -> str:
    seen = set(s)

    for i in range(25, -1, -1):
      if (chr(ord('a') + i) in seen and
              chr(ord('A') + i) in seen):
        return chr(ord('A') + i)

    return ''
