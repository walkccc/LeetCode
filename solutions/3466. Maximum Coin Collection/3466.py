class Solution:
  def maxCoins(self, lane1: list[int], lane2: list[int]) -> int:
    n = len(lane1)
    # dp[i][k] := the maximum number of coins at i-th mile with k switches
    dp = [[-math.inf] * 3 for _ in range(n)]
    dp[0][0] = lane1[0]
    dp[0][1] = lane2[0]

    for i in range(1, n):
      dp[i][0] = max(0, dp[i - 1][0]) + lane1[i]
      dp[i][1] = max(0, dp[i - 1][0], dp[i - 1][1]) + lane2[i]
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + lane1[i]

    return max(map(max, dp))
