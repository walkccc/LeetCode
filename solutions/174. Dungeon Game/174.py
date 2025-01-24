class Solution:
  def calculateMinimumHP(self, dungeon: list[list[int]]) -> int:
    m = len(dungeon)
    n = len(dungeon[0])
    dp = [math.inf] * (n + 1)
    dp[n - 1] = 1

    for i in reversed(range(m)):
      for j in reversed(range(n)):
        dp[j] = min(dp[j], dp[j + 1]) - dungeon[i][j]
        dp[j] = max(dp[j], 1)

    return dp[0]
