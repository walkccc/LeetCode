class Solution:
  def minFlipsMonoIncr(self, s: str) -> int:
    dp = [0] * 2

    for c in s:
      dp[0], dp[1] = dp[0] + (c == '1'), min(dp[0], dp[1]) + (c == '0')

    return min(dp)
