class Solution:
  def maxScore(self, nums: List[int]) -> int:
    return sum(num > 0
               for num in itertools.accumulate(sorted(nums, reverse=True)))
