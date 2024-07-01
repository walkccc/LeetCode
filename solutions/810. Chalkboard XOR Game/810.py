class Solution:
  def xorGame(self, nums: List[int]) -> bool:
    return functools.reduce(operator.xor, nums) == 0 or len(nums) % 2 == 0
