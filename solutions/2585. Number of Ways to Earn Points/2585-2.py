class Solution:
  def waysToReachTarget(self, target: int, types: list[list[int]]) -> int:
    kMod = 1_000_000_007
    # dp[j] := the number of ways to earn j points with the types so far
    dp = [1] + [0] * target

    for count, mark in types:
      for j in range(target, -1, -1):
        for solved in range(1, count + 1):
          if j - solved * mark >= 0:
            dp[j] += dp[j - solved * mark]
            dp[j] %= kMod

    return dp[target]
