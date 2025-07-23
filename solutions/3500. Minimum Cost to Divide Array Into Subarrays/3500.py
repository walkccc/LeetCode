class Solution:
  def minimumCost(self, nums: list[int], cost: list[int], k: int) -> int:
    n = len(nums)
    prefixNums = list(itertools.accumulate(nums, initial=0))
    prefixCost = list(itertools.accumulate(cost, initial=0))
    # dp[i] := the minimum cost to divide nums[i..n - 1] into subarrays
    dp = [math.inf] * n + [0]

    for i in range(n - 1, -1, -1):
      for j in range(i, n):
        dp[i] = min(dp[i],
                    prefixNums[j + 1] * (prefixCost[j + 1] - prefixCost[i]) +
                    k * (prefixCost[n] - prefixCost[i]) + dp[j + 1])

    return dp[0]
