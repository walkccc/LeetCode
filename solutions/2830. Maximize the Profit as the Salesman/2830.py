class Solution:
  def maximizeTheProfit(self, n: int, offers: list[list[int]]) -> int:
    # dp[i] := the maximum amount of gold of selling the first i houses
    dp = [0] * (n + 1)
    endToStartAndGolds = [[] for _ in range(n)]

    for start, end, gold in offers:
      endToStartAndGolds[end].append((start, gold))

    for end in range(1, n + 1):
      # Get at least the same gold as selling the first `end - 1` houses.
      dp[end] = dp[end - 1]
      for start, gold in endToStartAndGolds[end - 1]:
        dp[end] = max(dp[end], dp[start] + gold)

    return dp[n]
