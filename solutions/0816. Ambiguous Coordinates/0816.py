class Solution:
  def ambiguousCoordinates(self, s: str) -> List[str]:
    def splits(s: str) -> List[str]:
      if not s or len(s) > 1 and s[0] == s[-1] == '0':
        return []
      if s[-1] == '0':
        return [s]
      if s[0] == '0':
        return [s[0] + '.' + s[1:]]
      return [s] + [s[:i] + '.' + s[i:] for i in range(1, len(s))]

    ans = []
    s = s[1:-1]

    for i in range(1, len(s)):
      for x in splits(s[:i]):
        for y in splits(s[i:]):
          ans.append('(%s, %s)' % (x, y))

    return ans
