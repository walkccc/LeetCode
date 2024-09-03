class Solution:
  def sellingWood(self, m: int, n: int, prices: list[list[int]]) -> int:
    # dp[i][j] := the maximum money of cutting i x j piece of wood
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for h, w, price in prices:
      dp[h][w] = price

    for i in range(1, m + 1):
      for j in range(1, n + 1):
        for h in range(1, i // 2 + 1):
          dp[i][j] = max(dp[i][j], dp[h][j] + dp[i - h][j])
        for w in range(1, j // 2 + 1):
          dp[i][j] = max(dp[i][j], dp[i][w] + dp[i][j - w])

    return dp[m][n]
