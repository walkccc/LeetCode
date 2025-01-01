class Solution:
  def countPalindromicSubsequences(self, s: str) -> int:
    kMod = 1_000_000_007
    n = len(s)
    # dp[i][j] := the number of different non-empty palindromic subsequences in
    # s[i..j]
    dp = [[0] * n for _ in range(n)]

    for i in range(n):
      dp[i][i] = 1

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        if s[i] == s[j]:
          lo = i + 1
          hi = j - 1
          while lo <= hi and s[lo] != s[i]:
            lo += 1
          while lo <= hi and s[hi] != s[i]:
            hi -= 1
          if lo > hi:
            dp[i][j] = dp[i + 1][j - 1] * 2 + 2
          elif lo == hi:
            dp[i][j] = dp[i + 1][j - 1] * 2 + 1
          else:
            dp[i][j] = dp[i + 1][j - 1] * 2 - dp[lo + 1][hi - 1]
        else:
          dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]
        dp[i][j] = (dp[i][j] + kMod) % kMod

    return dp[0][n - 1]
