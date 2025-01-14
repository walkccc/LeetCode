class Solution:
  def smallestRangeI(self, nums: list[int], k: int) -> int:
    return max(0, max(nums) - min(nums) - 2 * k)
