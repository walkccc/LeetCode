class Solution:
  def replaceDigits(self, s: str) -> str:
    return ''.join(
        c if i % 2 == 0 else chr(ord(s[i - 1]) + int(c))
        for i, c in enumerate(s)
    )
