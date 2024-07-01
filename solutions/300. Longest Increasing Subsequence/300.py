class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:
    if not nums:
      return 0

    # dp[i] the length of LIS ending in nums[i]
    dp = [1] * len(nums)

    for i in range(1, len(nums)):
      for j in range(i):
        if nums[j] < nums[i]:
          dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)
