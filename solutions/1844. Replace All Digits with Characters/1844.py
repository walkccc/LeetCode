class Solution:
  def replaceDigits(self, s: str) -> str:
    chars = list(s)

    for i in range(1, len(chars), 2):
      chars[i] = chr(ord(chars[i - 1]) + ord(chars[i]) - ord('0'))

    return ''.join(chars)
