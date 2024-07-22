class Solution:
  def getMoneyAmount(self, n: int) -> int:
    # dp[i][j] := the minimum money you need to guarantee a win of picking i..j
    dp = [[0] * (n + 2) for _ in range(n + 2)]

    for d in range(1, n + 1):
      for i in range(1, n - d + 1):
        j = i + d
        dp[i][j] = math.inf
        for k in range(i, j + 1):
          dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k)

    return dp[1][n]
