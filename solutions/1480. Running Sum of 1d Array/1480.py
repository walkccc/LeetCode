class Solution:
  def runningSum(self, nums: list[int]) -> list[int]:
    return itertools.accumulate(nums)
