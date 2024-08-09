class Solution:
  def minDistance(self, word1: str, word2: str) -> int:
    k = self._lcs(word1, word2)
    return (len(word1) - k) + (len(word2) - k)

  def _lcs(self, a: str, b: str) -> int:
    m = len(a)
    n = len(b)
    # dp[i][j] := the length of LCS(a[0..i), b[0..j))
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
      for j in range(1, n + 1):
        if a[i - 1] == b[j - 1]:
          dp[i][j] = 1 + dp[i - 1][j - 1]
        else:
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]
