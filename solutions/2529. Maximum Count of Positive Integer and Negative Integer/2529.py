class Solution:
  def maximumCount(self, nums: list[int]) -> int:
    return max(sum(num > 0 for num in nums), sum(num < 0 for num in nums))
