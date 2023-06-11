class Solution:
  def numWays(self, steps: int, arrLen: int) -> int:
    kMod = 1_000_000_007
    # dp[i] := # of ways to stay on index i
    dp = [0] * min(steps // 2 + 1, arrLen)
    dp[0] = 1

    for _ in range(steps):
      newDp = [0] * min(steps // 2 + 1, arrLen)
      for i, ways in enumerate(dp):
        if ways > 0:
          for dx in (-1, 0, 1):
            nextIndex = i + dx
            if 0 <= nextIndex < len(dp):
              newDp[nextIndex] += ways
              newDp[nextIndex] %= kMod
      dp = newDp

    return dp[0]
