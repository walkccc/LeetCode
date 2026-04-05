class Solution:
  def maxCoins(self, lane1: list[int], lane2: list[int]) -> int:
    # dp[k] := the maximum number of coins at mile so far with k switches
    dp = (lane1[0], lane2[0], -math.inf)
    ans = max(dp)

    for i in range(1, len(lane1)):
      dp = (max(0, dp[0]) + lane1[i],
            max(0, dp[0], dp[1]) + lane2[i],
            max(dp[1], dp[2]) + lane1[i])
      ans = max(ans, max(dp))

    return ans
