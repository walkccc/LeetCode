class Solution:
  def maxScore(self, nums: list[int]) -> int:
    return sum(num > 0
               for num in itertools.accumulate(sorted(nums, reverse=True)))
