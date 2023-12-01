class Solution:
  def modifyString(self, s: str) -> str:
    ans = []

    def nextAvailable(ans: List[int], s: str, i: int) -> str:
      c = 'a'
      while (i > 0 and ans[i - 1] == c) or \
              (i + 1 < len(s) and c == s[i + 1]):
        c = chr(ord(c) + 1)
      return c

    for i, c in enumerate(s):
      if c == '?':
        ans.append(nextAvailable(ans, s, i))
      else:
        ans.append(c)

    return ''.join(ans)
