class Solution:
  def numberOfWays(self, n: int, x: int) -> int:
    kMod = 1_000_000_007
    # dp[i] := the number of ways to express i
    dp = [1] + [0] * n

    for a in range(1, n + 1):
      ax = a**x
      if ax > n:
        break
      for i in range(n, ax - 1, -1):
        dp[i] += dp[i - ax]
        dp[i] %= kMod

    return dp[n]
