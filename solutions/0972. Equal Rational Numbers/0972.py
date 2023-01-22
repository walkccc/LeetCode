class Solution:
  def isRationalEqual(self, S: str, T: str) -> bool:
    def valueOf(s: str) -> float:
      if s.find('(') == -1:
        return float(s)

      integer_nonRepeating = float(s[:s.find('(')])
      nonRepeatingLength = s.find('(') - s.find('.') - 1
      repeating = float(s[s.find('(') + 1: s.find(')')])
      repeatingLength = s.find(')') - s.find('(') - 1

      return integer_nonRepeating + repeating * 0.1**nonRepeatingLength * ratios[repeatingLength]

    ratios = [1, 1 / 9, 1 / 99, 1 / 999, 1 / 9999]

    return abs(valueOf(S) - valueOf(T)) < 1e-9
