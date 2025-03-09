class Solution:
  def minimumOperations(self, nums: list[int]) -> int:
    return sum(num % 3 != 0 for num in nums)
