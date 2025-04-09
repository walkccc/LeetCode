class Solution:
  def maximumAlternatingSubarraySum(self, nums: list[int]) -> int:
    ans = -math.inf
    even = 0  # the subarray sum starting from an even index
    odd = 0  # the subarray sum starting from an odd index

    for i in range(len(nums)):
      if i % 2 == 0:  # Must pick.
        even += nums[i]
      else:  # Start a fresh subarray or subtract `nums[i]`.
        even = max(0, even - nums[i])
      ans = max(ans, even)

    for i in range(1, len(nums)):
      if i % 2 == 1:  # Must pick.
        odd += nums[i]
      else:  # Start a fresh subarray or subtract `nums[i]`.
        odd = max(0, odd - nums[i])
      ans = max(ans, odd)

    return ans
