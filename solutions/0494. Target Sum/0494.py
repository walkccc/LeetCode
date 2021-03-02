class Solution:
  def findTargetSumWays(self, nums: List[int], S: int) -> int:
    summ = sum(nums)
    if summ < S or (summ + S) & 1:
      return 0

    def knapsack(target: int) -> int:
      # dp[i] := # of ways to sum to i by nums so far
      dp = [1] + [0] * summ

      for num in nums:
        for j in range(summ, num - 1, -1):
          dp[j] += dp[j - num]

      return dp[target]

    return knapsack((summ + S) // 2)
