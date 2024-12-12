class Solution:
  def xorBeauty(self, nums: list[int]) -> int:
    return functools.reduce(operator.xor, nums)
