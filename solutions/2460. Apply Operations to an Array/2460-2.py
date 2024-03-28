class Solution:
  def applyOperations(self, nums: List[int]) -> List[int]:
    j = 0
    for i in range(len(nums)):
      if i + 1 < len(nums) and nums[i] == nums[i + 1]:
        nums[i] *= 2
        nums[i + 1] = 0
      if nums[i] > 0:
        nums[i], nums[j] = nums[j], nums[i]
        j += 1
    return nums
