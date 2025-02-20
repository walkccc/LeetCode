class Solution:
  # Same as 2944. Minimum Number of Coins for Fruits
  def minimumCoins(self, prices: list[int]) -> int:
    n = len(prices)
    # Convert to 0-indexed for easy computation.
    # dp[i] := the minimum number of coins to acquire fruits[i:]
    dp = [math.inf] * n + [0]

    for i in range(n - 1, -1, -1):
      # Convert back to 1-indexed.
      for j in range(i + 1, min((i + 1) * 2 + 1, n + 1)):
        dp[i] = min(dp[i], prices[i] + dp[j])

    return dp[0]
