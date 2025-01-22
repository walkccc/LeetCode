class Solution:
  def decodeAtIndex(self, s: str, k: int) -> str:
    size = 0

    for c in s:
      if c.isdigit():
        size *= int(c)
      else:
        size += 1

    for c in reversed(s):
      k %= size
      if k == 0 and c.isalpha():
        return c
      if c.isdigit():
        size //= int(c)
      else:
        size -= 1
