class Solution:
  def countSubarrays(self, nums: list[int]) -> int:
    return sum(b == (a + c) * 2
               for a, b, c in zip(nums, nums[1:], nums[2:]))
