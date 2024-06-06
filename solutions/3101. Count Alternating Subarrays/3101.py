class Solution:
  def countAlternatingSubarrays(self, nums: List[int]) -> int:
    # dp[i] := the number of alternating subarrays ending in index i
    dp = [1] * len(nums)

    for i in range(1, len(nums)):
      if nums[i] != nums[i - 1]:
        dp[i] += dp[i - 1]

    return sum(dp)
