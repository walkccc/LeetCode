class Solution:
  def toHexspeak(self, num: str) -> str:
    s = hex(int(num)).upper()[2:].translate(str.maketrans('01', 'OI'))
    return 'ERROR' if any(c.isdigit() for c in s) else s
