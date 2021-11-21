class Solution:
  def isMatch(self, s: str, p: str) -> bool:
    m = len(s)
    n = len(p)

    # dp[i][j] := True if s[0..i) matches p[0..j)
    dp = [[False] * (n + 1) for _ in range(m + 1)]
    dp[0][0] = True

    def isMatch(c1, c2):
      return c1 == c2 or c2 == '.'

    for i in range(m + 1):
      for j in range(1, n + 1):
        if p[j - 1] == '*':
          noRepeat = dp[i][j - 2]
          doRepeat = i > 0 and isMatch(
              s[i - 1], p[j - 2]) and dp[i - 1][j]
          dp[i][j] = noRepeat or doRepeat
        else:
          dp[i][j] = i > 0 and isMatch(
              s[i - 1], p[j - 1]) and dp[i - 1][j - 1]

    return dp[m][n]
