class Solution:
  def specialArray(self, nums: list[int]) -> int:
    nums.sort()

    if nums[0] >= len(nums):
      return len(nums)

    for i, (a, b) in enumerate(itertools.pairwise(nums)):
      count = len(nums) - i - 1
      if a < count and b >= count:
        return count

    return -1
