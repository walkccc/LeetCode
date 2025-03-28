class Solution:
  # Similar to 516. Longest Palindromic Subsequence
  def longestPalindromicSubsequence(self, s: str, k: int) -> int:
    n = len(s)
    # dp[i][j][op] := the length of LPS(s[i..j]) with at most `op` operations
    dp = [[[0] * (k + 1) for _ in range(n)] for _ in range(n)]

    for i in range(n):
      for op in range(k + 1):
        dp[i][i][op] = 1

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        for op in range(k + 1):
          if s[i] == s[j]:
            dp[i][j][op] = 2 + dp[i + 1][j - 1][op]
          else:
            dp[i][j][op] = max(dp[i + 1][j][op], dp[i][j - 1][op])
            cost = self._getCost(s[i], s[j])
            if cost <= op:
              dp[i][j][op] = max(dp[i][j][op], 2 + dp[i + 1][j - 1][op - cost])

    return dp[0][n - 1][k]

  def _getCost(self, a: str, b: str) -> int:
    dist = abs(ord(a) - ord(b))
    return min(dist, 26 - dist)
