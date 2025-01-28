class Solution:
  def minimumCost(self, nums: list[int]) -> int:
    kMax = 50
    min1 = kMax
    min2 = kMax

    for i in range(1, len(nums)):
      if nums[i] < min1:
        min2 = min1
        min1 = nums[i]
      elif nums[i] < min2:
        min2 = nums[i]

    return nums[0] + min1 + min2
