class Solution:
  def stoneGame(self, piles: List[int]) -> bool:
    n = len(piles)
    dp = piles.copy()

    for d in range(1, n):
      for j in range(n - 1, d - 1, -1):
        i = j - d
        dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1])

    return dp[n - 1] > 0
