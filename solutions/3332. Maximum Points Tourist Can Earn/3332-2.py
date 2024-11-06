class Solution:
  def maxScore(
      self,
      n: int,
      k: int,
      stayScore: list[list[int]],
      travelScore: list[list[int]]
  ) -> int:
    # dp[j] := the maximum score after days so far being at city j
    dp = [0] * n

    for i in range(k):
      newDp = [0] * n
      for dest in range(n):
        # 1. Stay at the current city.
        newDp[dest] = dp[dest] + stayScore[i][dest]
        # 2. Travel from any other city.
        for curr in range(n):
          if curr != dest:
            newDp[dest] = max(newDp[dest],
                              dp[curr] + travelScore[curr][dest])
      dp = newDp

    return max(dp)
