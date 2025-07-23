class Solution:
  def minSideJumps(self, obstacles: list[int]) -> int:
    INF = 1e6
    # dp[i] := the minimum jump to reach the i-th lane
    dp = [INF, 1, 0, 1]

    for obstacle in obstacles:
      print(dp)
      if obstacle > 0:
        dp[obstacle] = INF
      for i in range(1, 4):  # the current
        if i != obstacle:
          for j in range(1, 4):  # the previous
            dp[i] = min(dp[i], dp[j] + (0 if i == j else 1))

    return min(dp)
