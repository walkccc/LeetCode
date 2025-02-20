class Solution:
  # Same as 3205. Maximum Array Hopping Score I
  def maxScore(self, nums: list[int]) -> int:
    # The optimal jump is the maximum number in the remaining suffix.
    return sum(itertools.accumulate(nums[:0:-1], max))
