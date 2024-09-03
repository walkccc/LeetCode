class Solution:
  def subsetXORSum(self, nums: list[int]) -> int:
    return functools.reduce(operator.or_, nums) << len(nums) - 1
