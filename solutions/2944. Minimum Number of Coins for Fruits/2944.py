class Solution:
  def minimumCoins(self, prices: List[int]) -> int:
    n = len(prices)
    # Convert to 0-index for easy computation.
    # dp[i] := the minimum number of coins to acquire fruits[i:]
    dp = [math.inf] * (n + 1)
    dp[n] = 0

    for i in range(n - 1, -1, -1):
      # Convert back to 1-index.
      for j in range(i + 1, min(i + 1 + i + 1 + 1, n + 1)):
        dp[i] = min(dp[i], dp[j] + prices[i])

    return dp[0]
