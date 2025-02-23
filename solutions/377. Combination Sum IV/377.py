class Solution:
  def combinationSum4(self, nums: list[int], target: int) -> int:
    dp = [1] + [-1] * target

    def dfs(target: int) -> int:
      if target < 0:
        return 0
      if dp[target] != -1:
        return dp[target]

      dp[target] = sum(dfs(target - num) for num in nums)
      return dp[target]

    return dfs(target)
