class Solution:
  def tribonacci(self, n: int) -> int:
    if n < 2:
      return n

    dp = [0, 1, 1]

    for _ in range(3, n + 1):
      dp[0], dp[1], dp[2] = dp[1], dp[2], sum(dp)

    return dp[2]
