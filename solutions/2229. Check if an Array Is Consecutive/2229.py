class Solution:
  def isConsecutive(self, nums: list[int]) -> bool:
    return max(nums) - min(nums) + 1 == len(set(nums)) == len(nums)
