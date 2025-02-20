class Solution:
  def isMonotonic(self, nums: list[int]) -> bool:
    increasing = True
    decreasing = True

    for i in range(1, len(nums)):
      increasing &= nums[i - 1] <= nums[i]
      decreasing &= nums[i - 1] >= nums[i]

    return increasing or decreasing
