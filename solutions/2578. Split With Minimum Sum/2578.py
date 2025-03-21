class Solution:
  def splitNum(self, num: int) -> int:
    s = ''.join(sorted(str(num)))
    return sum(map(int, (s[::2], s[1::2])))
