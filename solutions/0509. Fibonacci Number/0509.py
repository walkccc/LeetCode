class Solution:
  def fib(self, N: int) -> int:
    if N < 2:
      return N

    dp = [0, 0, 1]

    for i in range(2, N + 1):
      dp[0] = dp[1]
      dp[1] = dp[2]
      dp[2] = dp[0] + dp[1]

    return dp[2]
