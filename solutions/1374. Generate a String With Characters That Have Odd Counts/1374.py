class Solution:
  def generateTheString(self, n: int) -> str:
    s = 'a' * n
    if n % 2 == 0:
      s = s[:-1] + 'b'
    return s
