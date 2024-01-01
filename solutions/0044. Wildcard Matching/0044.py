class Solution:
  def isMatch(self, s: str, p: str) -> bool:
    m = len(s)
    n = len(p)
    # dp[i][j] := True if s[0..i) matches p[0..j)
    dp = [[False] * (n + 1) for _ in range(m + 1)]
    dp[0][0] = True

    def isMatch(i: int, j: int) -> bool:
      return i >= 0 and p[j] == '?' or s[i] == p[j]

    for j, c in enumerate(p):
      if c == '*':
        dp[0][j + 1] = dp[0][j]

    for i in range(m):
      for j in range(n):
        if p[j] == '*':
          matchEmpty = dp[i + 1][j]
          matchSome = dp[i][j + 1]
          dp[i + 1][j + 1] = matchEmpty or matchSome
        elif isMatch(i, j):
          dp[i + 1][j + 1] = dp[i][j]

    return dp[m][n]
