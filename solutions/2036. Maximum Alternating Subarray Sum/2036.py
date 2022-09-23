class Solution:
  def maximumAlternatingSubarraySum(self, nums: List[int]) -> int:
    ans = -math.inf
    even = 0  # subarray sum starting from an even index
    odd = 0  # subarray sum starting from an odd index

    for i in range(len(nums)):
      if (i & 1) == 0:  # must pick
        even += nums[i]
      else:  # fresh start or minus
        even = max(0, even - nums[i])
      ans = max(ans, even)

    for i in range(1, len(nums)):
      if i & 1:  # must pick
        odd += nums[i]
      else:  # fresh start or minus
        odd = max(0, odd - nums[i])
      ans = max(ans, odd)

    return ans
