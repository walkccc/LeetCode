class Solution:
  def validStrings(self, n: int) -> list[str]:
    ans = []

    def dfs(n: int, s: list[str]) -> None:
      if n == 0:
        ans.append(''.join(s))
        return
      if not s or s[-1] == '1':
        s.append('0')
        dfs(n - 1, s)
        s.pop()
      s.append('1')
      dfs(n - 1, s)
      s.pop()

    dfs(n, [])
    return ans
