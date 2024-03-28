class Solution:
  def longestSubarray(self, nums: List[int]) -> int:
    l = 0
    count0 = 0

    for num in nums:
      if num == 0:
        count0 += 1
      if count0 > 1:
        if nums[l] == 0:
          count0 -= 1
        l += 1

    return len(nums) - l - 1
