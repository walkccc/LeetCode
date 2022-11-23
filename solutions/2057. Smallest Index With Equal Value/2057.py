class Solution:
  def smallestEqual(self, nums: List[int]) -> int:
    return next((i for i, num in enumerate(nums) if i % 10 == num), -1)
