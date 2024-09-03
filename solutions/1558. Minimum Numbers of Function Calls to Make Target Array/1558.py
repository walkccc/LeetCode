class Solution:
  def minOperations(self, nums: list[int]) -> int:
    maxNum = max(nums)
    return (sum(num.bit_count() for num in nums) +
            (0 if maxNum == 0 else maxNum.bit_length() - 1))
