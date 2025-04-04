class Solution:
  def minimumOperations(self, nums: list[int]) -> int:
    return len(set(nums) - {0})
