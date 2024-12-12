class Solution:
  def minimizeSum(self, nums: list[int]) -> int:
    nums.sort()
    # Can always change the number to any other number in `nums`, so `low` becomes 0.
    # Thus, rephrase the problem as finding the minimum `high`.
    highOfChangingTwoMins = nums[-1] - nums[2]
    highOfChangingTwoMaxs = nums[-3] - nums[0]
    highOfChangingMinAndMax = nums[-2] - nums[1]
    return min(highOfChangingTwoMins, highOfChangingTwoMaxs,
               highOfChangingMinAndMax)
