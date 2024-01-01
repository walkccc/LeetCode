class Solution:
  def maximumJumps(self, nums: List[int], target: int) -> int:
    n = len(nums)
    # dp[i] := the maximum number of jumps to reach i from 0
    dp = [-1] * n
    dp[0] = 0

    for j in range(1, n):
      for i in range(j):
        if dp[i] != -1 and abs(nums[j] - nums[i]) <= target:
          dp[j] = max(dp[j], dp[i] + 1)

    return dp[-1]
