class Solution:
  def xorBeauty(self, nums: List[int]) -> int:
    return functools.reduce(operator.xor, nums)
