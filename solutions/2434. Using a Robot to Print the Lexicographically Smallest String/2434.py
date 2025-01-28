class Solution:
  def robotWithString(self, s: str) -> str:
    ans = []
    count = collections.Counter(s)
    stack = []

    for c in s:
      stack.append(c)
      count[c] -= 1
      minChar = self._getMinChar(count)
      while stack and stack[-1] <= minChar:
        ans.append(stack.pop())

    return ''.join(ans + stack[::-1])

  def _getMinChar(self, count: list[int]) -> str:
    for c in string.ascii_lowercase:
      if count[c]:
        return c
    return 'a'
