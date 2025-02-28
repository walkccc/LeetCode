class Solution:
  def findMaxForm(self, strs: list[str], m: int, n: int) -> int:
    # dp[i][j] := the maximum size of the subset given i 0s and j 1s are
    # available
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for s in strs:
      zeros = s.count('0')
      ones = len(s) - zeros
      for i in range(m, zeros - 1, -1):
        for j in range(n, ones - 1, -1):
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)

    return dp[m][n]
