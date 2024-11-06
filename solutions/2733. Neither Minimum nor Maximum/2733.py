class Solution:
  def findNonMinOrMax(self, nums: list[int]) -> int:
    return -1 if len(nums) < 3 else sorted(nums[:3])[1]
