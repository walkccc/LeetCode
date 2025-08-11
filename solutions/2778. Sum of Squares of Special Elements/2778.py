class Solution:
  def sumOfSquares(self, nums: list[int]) -> int:
    return sum(num**2 for i, num in enumerate(nums)
               if len(nums) % (i + 1) == 0)
