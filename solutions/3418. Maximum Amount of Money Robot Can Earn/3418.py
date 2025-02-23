class Solution:
  def maximumAmount(self, coins: list[list[int]]) -> int:
    m = len(coins)
    n = len(coins[0])
    # dp[i][j][k] := the maximum profit at position (i, j) with k remaining
    # neutralizations
    dp = [[[-math.inf] * 4 for _ in range(n)] for _ in range(m)]

    # Base case: the robot starts at the top-left corner.
    dp[0][0][2] = coins[0][0]
    if coins[0][0] < 0:
      dp[0][0][1] = 0  # Neutralize the robber.

    for i in range(m):
      for j in range(n):
        for k in range(3):  # for each number of remaining neutralizations
          if i > 0:
            dp[i][j][k] = max(dp[i][j][k],
                              dp[i - 1][j][k] + coins[i][j],
                              dp[i - 1][j][k + 1])
          if j > 0:
            dp[i][j][k] = max(dp[i][j][k],
                              dp[i][j - 1][k] + coins[i][j],
                              dp[i][j - 1][k + 1])

    return max(dp[-1][-1])
