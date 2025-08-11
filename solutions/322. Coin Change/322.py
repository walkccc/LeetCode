class Solution:
  def coinChange(self, coins: list[int], amount: int) -> int:
    # dp[i] := the minimum number Of coins to make up i
    dp = [0] + [amount + 1] * amount

    for coin in coins:
      for i in range(coin, amount + 1):
        dp[i] = min(dp[i], dp[i - coin] + 1)

    return -1 if dp[amount] == amount + 1 else dp[amount]
