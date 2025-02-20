class Solution:
  def xorGame(self, nums: list[int]) -> bool:
    return functools.reduce(operator.xor, nums) == 0 or len(nums) % 2 == 0
