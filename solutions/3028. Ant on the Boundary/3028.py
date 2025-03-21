class Solution:
  def returnToBoundaryCount(self, nums: list[int]) -> int:
    return sum(prefix == 0 for prefix in itertools.accumulate(nums))
