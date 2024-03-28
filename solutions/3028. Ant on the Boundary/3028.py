class Solution:
  def returnToBoundaryCount(self, nums: List[int]) -> int:
    return sum(prefix == 0 for prefix in itertools.accumulate(nums))
