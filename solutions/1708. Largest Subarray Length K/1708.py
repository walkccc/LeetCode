class Solution:
  def largestSubarray(self, nums: List[int], k: int) -> List[int]:
    maxi = max(nums[:len(nums) - k + 1])
    i = nums.index(maxi)
    return nums[i:i + k]
