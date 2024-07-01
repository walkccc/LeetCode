class Solution:
  def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
    # dp[i][j] := the maximum size of the subset given i 0s and j 1s are
    # available
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for s in strs:
      count0 = s.count('0')
      count1 = len(s) - count0
      for i in range(m, count0 - 1, -1):
        for j in range(n, count1 - 1, -1):
          dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1)

    return dp[m][n]
