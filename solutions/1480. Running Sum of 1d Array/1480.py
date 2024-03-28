class Solution:
  def runningSum(self, nums: List[int]) -> List[int]:
    return itertools.accumulate(nums)
