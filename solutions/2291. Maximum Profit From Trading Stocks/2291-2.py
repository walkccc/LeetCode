class Solution:
  def maximumProfit(self, present: List[int], future: List[int], budget: int) -> int:
    n = len(present)
    # dp[i] := max profit of buying present so far with i budget
    dp = [0] * (budget + 1)

    for p, f in zip(present, future):
      for j in range(budget, p - 1, -1):
        dp[j] = max(dp[j], f - p + dp[j - p])

    return dp[budget]
