class Solution:
  def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
    m = len(dungeon)
    n = len(dungeon[0])

    dp = [inf] * (n + 1)
    dp[n - 1] = 1

    for i in range(m)[::-1]:
      for j in range(n)[::-1]:
        dp[j] = min(dp[j], dp[j + 1]) - dungeon[i][j]
        dp[j] = max(dp[j], 1)

    return dp[0]
