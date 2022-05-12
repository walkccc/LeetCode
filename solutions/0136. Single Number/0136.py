class Solution:
  def singleNumber(self, nums: List[int]) -> int:
    return reduce(lambda x, y: x ^ y, nums, 0)
