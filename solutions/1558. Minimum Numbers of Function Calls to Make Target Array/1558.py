class Solution:
  def minOperations(self, nums: list[int]) -> int:
    mx = max(nums)
    return (sum(num.bit_count() for num in nums) +
            (0 if mx == 0 else mx.bit_length() - 1))
