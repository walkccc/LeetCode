class Solution:
  def maxDiff(self, num: int) -> int:
    s = str(num)

    def firstNot(s: str, t: str) -> int:
      for i, c in enumerate(s):
        if all(c != d for d in t):
          return i
      return 0

    firstNot9 = firstNot(s, '9')
    firstNot01 = firstNot(s, '01')
    a = s.replace(s[firstNot9], '9')
    b = s.replace(s[firstNot01], '1' if firstNot01 == 0 else '0')
    return int(a) - int(b)
