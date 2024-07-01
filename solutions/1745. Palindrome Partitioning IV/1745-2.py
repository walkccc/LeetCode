class Solution:
  def checkPartitioning(self, s: str) -> bool:
    n = len(s)
    # dp[i][j] := true if s[i..j] is a palindrome
    dp = [[False] * n for _ in range(n)]

    for i in range(n):
      dp[i][i] = True

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        if s[i] == s[j]:
          dp[i][j] = i + 1 > j - 1 or dp[i + 1][j - 1]

    for i in range(n):
      for j in range(i + 1, n):
        if dp[0][i] and dp[i + 1][j] and dp[j + 1][n - 1]:
          return True

    return False
