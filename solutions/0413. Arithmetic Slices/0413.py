class Solution:
  def numberOfArithmeticSlices(self, nums: List[int]) -> int:
    n = len(nums)
    if n < 3:
      return 0

    dp = [0] * n  # dp[i] := the number of arithmetic slices ending in index i

    for i in range(2, len(nums)):
      if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]:
        dp[i] = dp[i - 1] + 1

    return sum(dp)
