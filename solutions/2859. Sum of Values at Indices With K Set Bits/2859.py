class Solution:
  def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
    return sum(num for i, num in enumerate(nums)
               if i.bit_count() == k)
