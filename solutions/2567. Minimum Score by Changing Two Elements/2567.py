class Solution:
  def minimizeSum(self, nums: List[int]) -> int:
    nums.sort()
    # Can always change the num to any other num in nums, so `low` becomes 0.
    # So, we can rephrase the problem as finding the min `high`.
    highOfChangingTwoMins = nums[-1] - nums[2]
    highOfChangingTwoMaxs = nums[-3] - nums[0]
    highOfChangingMinAndMax = nums[-2] - nums[1]
    return min(highOfChangingTwoMins, highOfChangingTwoMaxs,
               highOfChangingMinAndMax)
