class Solution:
  def waysToReachTarget(self, target: int, types: list[list[int]]) -> int:
    kMod = 1_000_000_007
    # dp[i][j] := the number of ways to earn j points with the first i types
    dp = [[0] * (target + 1) for _ in range(len(types) + 1)]
    dp[0][0] = 1

    for i in range(1, len(types) + 1):
      count = types[i - 1][0]
      mark = types[i - 1][1]
      for j in range(target + 1):
        for solved in range(count + 1):
          if j - solved * mark >= 0:
            dp[i][j] += dp[i - 1][j - solved * mark]
            dp[i][j] %= kMod

    return dp[len(types)][target]
