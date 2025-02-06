class Solution:
  def minScoreTriangulation(self, values: list[int]) -> int:
    n = len(values)
    dp = [[0] * n for _ in range(n)]

    for j in range(2, n):
      for i in range(j - 2, -1, -1):
        dp[i][j] = math.inf
        for k in range(i + 1, j):
          dp[i][j] = min(dp[i][j], dp[i][k] + values[i]
                         * values[k] * values[j] + dp[k][j])

    return dp[0][n - 1]
