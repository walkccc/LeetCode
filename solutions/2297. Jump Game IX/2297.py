class Solution:
  def minCost(self, nums: list[int], costs: list[int]) -> int:
    # dp[i] := the minimum cost to jump to i
    dp = [math.inf] * len(nums)
    maxStack = []
    minStack = []

    dp[0] = 0

    for i, num in enumerate(nums):
      while maxStack and num >= nums[maxStack[-1]]:
        dp[i] = min(dp[i], dp[maxStack.pop()] + costs[i])
      while minStack and num < nums[minStack[-1]]:
        dp[i] = min(dp[i], dp[minStack.pop()] + costs[i])
      maxStack.append(i)
      minStack.append(i)

    return dp[-1]
