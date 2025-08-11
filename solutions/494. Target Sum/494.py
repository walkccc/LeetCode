class Solution:
  def findTargetSumWays(self, nums: list[int], target: int) -> int:
    summ = sum(nums)
    if summ < abs(target) or (summ + target) % 2 == 1:
      return 0

    def knapsack(target: int) -> int:
      # dp[i] := the number of ways to sum to i by nums so far
      dp = [1] + [0] * summ

      for num in nums:
        for j in range(summ, num - 1, -1):
          dp[j] += dp[j - num]

      return dp[target]

    return knapsack((summ + target) // 2)
