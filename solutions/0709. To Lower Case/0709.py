class Solution:
  def toLowerCase(self, str: str) -> str:
    return ''.join(chr(ord(c) + 32) if 'A' <= c <= 'Z' else c for c in str)
