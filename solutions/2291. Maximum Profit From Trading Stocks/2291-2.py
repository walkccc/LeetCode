class Solution:
  def maximumProfit(
      self,
      present: list[int],
      future: list[int],
      budget: int,
  ) -> int:
    # dp[i] := the maximum profit of buying present so far with i budget
    dp = [0] * (budget + 1)

    for p, f in zip(present, future):
      for j in range(budget, p - 1, -1):
        dp[j] = max(dp[j], f - p + dp[j - p])

    return dp[budget]
