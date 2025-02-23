class Solution:
  def makeGood(self, s: str) -> str:
    ans = []
    for c in s:
      if ans and self._is_bad_pair(ans[-1], c):
        ans.pop()
      else:
        ans.append(c)
    return ''.join(ans)

  def _is_bad_pair(self, a: str, b: str) -> bool:
    return a != b and a.lower() == b.lower()
