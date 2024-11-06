class Solution:
  def expand(self, s: str) -> list[str]:
    ans = []

    def dfs(i: int, path: list[str]) -> None:
      if i == len(s):
        ans.append(''.join(path))
        return
      if s[i] == '{':
        nextRightBraceIndex = s.find('}', i)
        for c in s[i + 1:nextRightBraceIndex].split(','):
          path.append(c)
          dfs(nextRightBraceIndex + 1, path)
          path.pop()
      else:  # s[i] != '{'
        path.append(s[i])
        dfs(i + 1, path)
        path.pop()

    dfs(0, [])
    return sorted(ans)
