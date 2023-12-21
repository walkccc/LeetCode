class Solution:
  def maximumProfit(self, present: List[int], future: List[int], budget: int) -> int:
    n = len(present)
    # dp[i][j] := the maximum profit of buying present[0..i) with j budget
    dp = [[0] * (budget + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
      profit = future[i - 1] - present[i - 1]
      for j in range(budget + 1):
        if j < present[i - 1]:
          dp[i][j] = dp[i - 1][j]
        else:
          dp[i][j] = max(dp[i - 1][j], profit + dp[i - 1][j - present[i - 1]])

    return dp[n][budget]
