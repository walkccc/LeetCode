class Solution:
  def transformArray(self, nums: list[int]) -> list[int]:
    return ([0] * sum(num % 2 == 0 for num in nums) +
            [1] * sum(num % 2 == 1 for num in nums))
