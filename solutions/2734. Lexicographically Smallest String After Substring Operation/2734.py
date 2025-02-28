class Solution:
  def smallestString(self, s: str) -> str:
    chars = list(s)
    n = len(s)
    i = 0

    while i < n and chars[i] == 'a':
      i += 1
    if i == n:
      chars[-1] = 'z'
      return ''.join(chars)

    while i < n and s[i] != 'a':
      chars[i] = chr(ord(chars[i]) - 1)
      i += 1

    return ''.join(chars)
