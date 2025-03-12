class Solution:
  def maxScore(
      self,
      n: int,
      k: int,
      stayScore: list[list[int]],
      travelScore: list[list[int]]
  ) -> int:
    # dp[i][j] := the maximum score after i days being at city j
    dp = [[0] * n for _ in range(k + 1)]

    for i in range(1, k + 1):
      for dest in range(n):
        # 1. Stay at the current city.
        dp[i][dest] = dp[i - 1][dest] + stayScore[i - 1][dest]
        # 2. Travel from any other city.
        for curr in range(n):
          if curr != dest:
            dp[i][dest] = max(dp[i][dest],
                              dp[i - 1][curr] + travelScore[curr][dest])

    return max(dp[k])
