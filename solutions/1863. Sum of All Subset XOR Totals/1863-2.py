class Solution:
  def subsetXORSum(self, nums: List[int]) -> int:
    return functools.reduce(operator.or_, nums) << len(nums) - 1
