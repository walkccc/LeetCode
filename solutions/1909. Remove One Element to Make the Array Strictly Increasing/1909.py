class Solution:
  def canBeIncreasing(self, nums: list[int]) -> bool:
    removed = False

    for i in range(1, len(nums)):
      if nums[i - 1] >= nums[i]:
        if removed:
          return False
        removed = True  # Remove nums[i - 1].
        if i > 1 and nums[i - 2] >= nums[i]:
          nums[i] = nums[i - 1]  # Remove nums[i] instead.

    return True
