class Solution:
  def findTargetSumWays(self, nums: List[int], target: int) -> int:
    summ = sum(nums)
    if summ < abs(target) or (summ + target) & 1:
      return 0

    def knapsack(nums: List[int], target: int) -> int:
      # dp[i] := # of ways to sum to i by nums so far
      dp = [0] * (target + 1)
      dp[0] = 1

      for num in nums:
        for i in range(target, num - 1, -1):
          dp[i] += dp[i - num]

      return dp[target]

    return knapsack(nums, (summ + target) // 2)
