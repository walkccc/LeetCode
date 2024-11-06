class Solution:
  def longestPalindromeSubseq(self, s: str) -> int:
    n = len(s)
    # dp[i][j][k] := the length of LPS(s[i..j]), where the previous letter is
    # ('a' + k).
    dp = [[[0] * 27 for _ in range(n)] for _ in range(n)]

    for d in range(1, n):
      for i in range(n - d):
        for k in range(27):
          j = i + d
          if s[i] == s[j] and s[i] != chr(ord('a') + k):
            dp[i][j][k] = dp[i + 1][j - 1][ord(s[i]) - ord('a')] + 2
          else:
            dp[i][j][k] = max(dp[i + 1][j][k], dp[i][j - 1][k])

    return dp[0][n - 1][26]
