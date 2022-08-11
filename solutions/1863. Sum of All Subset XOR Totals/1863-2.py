class Solution:
  def subsetXORSum(self, nums: List[int]) -> int:
    return reduce(operator.or_, nums) << len(nums) - 1
