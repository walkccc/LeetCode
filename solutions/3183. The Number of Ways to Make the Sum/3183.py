class Solution:
  def numberOfWays(self, n: int) -> int:
    MOD = 1_000_000_007
    # dp[i] := the number of ways to make the sum of i using coins 1, 2, and 6
    dp = [1] + [0] * n

    for coin in (1, 2, 6):
      for i in range(coin, n + 1):
        dp[i] = (dp[i] + dp[i - coin]) % MOD

    ans = dp[n]
    if n - 4 >= 0:
      ans = (ans + dp[n - 4]) % MOD
    if n - 8 >= 0:
      ans = (ans + dp[n - 8]) % MOD
    return ans
