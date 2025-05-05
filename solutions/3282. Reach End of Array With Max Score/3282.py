class Solution:
  # Similar to 3205. Maximum Array Hopping Score I
  def findMaximumScore(self, nums: list[int]) -> int:
    return sum(itertools.accumulate(nums[:-1], max))
