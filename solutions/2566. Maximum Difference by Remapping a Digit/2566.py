class Solution:
  def minMaxDifference(self, num: int) -> int:
    s = str(num)
    to9 = s[self._firstNotNineIndex(s)]
    to0 = s[0]
    return int(s.replace(to9, '9')) - int(s.replace(to0, '0'))

  def _firstNotNineIndex(self, s: str) -> int:
    for i, c in enumerate(s):
      if c != '9':
        return i
    return 0
