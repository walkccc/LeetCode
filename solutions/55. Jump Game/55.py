class Solution:
  def canJump(self, nums: list[int]) -> bool:
    i = 0
    reach = 0

    while i < len(nums) and i <= reach:
      reach = max(reach, i + nums[i])
      i += 1

    return i == len(nums)
