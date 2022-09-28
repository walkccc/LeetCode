class Solution:
  def canBeIncreasing(self, nums: List[int]) -> bool:
    removed = False

    for i in range(1, len(nums)):
      if nums[i - 1] >= nums[i]:
        if removed:
          return False
        removed = True  # remove nums[i - 1]
        if i > 1 and nums[i - 2] >= nums[i]:
          nums[i] = nums[i - 1]  # remove nums[i] instead

    return True
