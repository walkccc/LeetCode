class Solution:
  def minFlipsMonoIncr(self, S: str) -> int:
    dp = [0] * 2

    for i, c in enumerate(S):
      dp[0], dp[1] = dp[0] + (c == '1'), min(dp[0], dp[1]) + (c == '0')

    return min(dp[0], dp[1])
