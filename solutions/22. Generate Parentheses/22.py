class Solution:
  def generateParenthesis(self, n):
    ans = []

    def dfs(l: int, r: int, s: str) -> None:
      if l == 0 and r == 0:
        ans.append(s)
      if l > 0:
        dfs(l - 1, r, s + '(')
      if l < r:
        dfs(l, r - 1, s + ')')

    dfs(n, n, '')
    return ans
