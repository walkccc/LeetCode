class Solution:
  def minOperations(self, nums: list[int], k: int) -> int:
    return functools.reduce(operator.xor, nums, k).bit_count()
