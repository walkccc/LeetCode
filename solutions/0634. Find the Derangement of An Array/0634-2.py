class Solution:
  def findDerangement(self, n: int) -> int:
    kMod = 1_000_000_007
    dp = [1] + [0] * n

    for i in range(2, n + 1):
      dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % kMod

    return dp[n]
