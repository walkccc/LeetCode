class Solution:
  def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
    ans = ''
    count = collections.Counter(s)

    while True:
      addOne = ans and self._shouldAddOne(ans, count)
      c = self._getLargestChar(ans, count)
      if c == ' ':
        break
      repeats = 1 if addOne else min(count[c], repeatLimit)
      ans += c * repeats
      count[c] -= repeats

    return ans

  def _shouldAddOne(self, ans: str, count: collections.Counter) -> bool:
    for c in reversed(string.ascii_lowercase):
      if count[c]:
        return ans[-1] == c
    return False

  def _getLargestChar(self, ans: str, count: collections.Counter) -> int:
    for c in reversed(string.ascii_lowercase):
      if count[c] and (not ans or ans[-1] != c):
        return c
    return ' '
