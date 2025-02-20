class Solution:
  def decodeString(self, s: str) -> str:
    ans = ''

    while self.i < len(s) and s[self.i] != ']':
      if s[self.i].isdigit():
        k = 0
        while self.i < len(s) and s[self.i].isdigit():
          k = k * 10 + int(s[self.i])
          self.i += 1
        self.i += 1  # '['
        decodedString = self.decodeString(s)
        self.i += 1  # ']'
        ans += k * decodedString
      else:
        ans += s[self.i]
        self.i += 1

    return ans

  i = 0
