class Solution:
  def minimumCost(self, nums: list[int]) -> int:
    MAX = 50
    min1 = MAX
    min2 = MAX

    for i in range(1, len(nums)):
      if nums[i] < min1:
        min2 = min1
        min1 = nums[i]
      elif nums[i] < min2:
        min2 = nums[i]

    return nums[0] + min1 + min2
