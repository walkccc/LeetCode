class Solution:
  def numRollsToTarget(self, d: int, f: int, target: int) -> int:
    def dfs(d: int, target: int) -> int:
      if d == 0 or target <= 0:
        return d == 0 and target == 0
      if dp[d][target]:
        return dp[d][target] - 1  # -1 here

      ans = 0

      for i in range(1, f + 1):
        ans = (ans + dfs(d - 1, target - i)) % kMod

      dp[d][target] = ans + 1  # +1 here
      return ans

    kMod = int(1e9 + 7)
    dp = [[0] * (target + 1) for _ in range(d + 1)]

    return dfs(d, target)
