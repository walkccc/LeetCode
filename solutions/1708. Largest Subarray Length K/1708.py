class Solution:
  def largestSubarray(self, nums: list[int], k: int) -> list[int]:
    mx = max(nums[:len(nums) - k + 1])
    i = nums.index(mx)
    return nums[i:i + k]
