class Solution:
  def singleNumber(self, nums: List[int]) -> int:
    return functools.reduce(operator.xor, nums, 0)
