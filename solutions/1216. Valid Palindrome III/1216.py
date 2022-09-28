class Solution:
  def isValidPalindrome(self, s: str, k: int) -> bool:
    return len(s) - self._longestPalindromeSubseq(s) <= k

  # same as 516. Longest Palindromic Subsequence
  def _longestPalindromeSubseq(self, s: str) -> int:
    n = len(s)
    # dp[i][j] := LPS's length in s[i..j]
    dp = [[0] * n for _ in range(n)]

    for i in range(n):
      dp[i][i] = 1

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        if s[i] == s[j]:
          dp[i][j] = 2 + dp[i + 1][j - 1]
        else:
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

    return dp[0][n - 1]
