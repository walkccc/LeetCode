class Solution:
  def myAtoi(self, s: str) -> int:
    s = s.strip()
    if not s:
      return 0

    sign = -1 if s[0] == '-' else 1
    if s[0] in {'-', '+'}:
      s = s[1:]

    num = 0

    for c in s:
      if not c.isdigit():
        break
      num = num * 10 + ord(c) - ord('0')
      if sign * num <= -2**31:
        return -2**31
      if sign * num >= 2**31 - 1:
        return 2**31 - 1

    return sign * num
