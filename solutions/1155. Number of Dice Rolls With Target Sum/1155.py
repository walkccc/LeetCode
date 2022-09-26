class Solution:
  def numRollsToTarget(self, n: int, k: int, target: int) -> int:
    kMod = 1_000_000_007
    dp = [1] + [0] * target

    for _ in range(n):  # n dices
      newDp = [0] * (target + 1)
      for i in range(1, k + 1):  # number 1, 2, ..., f
        for t in range(i, target + 1):  # possible targets
          newDp[t] += dp[t - i]
          newDp[t] %= kMod
      dp = newDp

    return dp[target]
