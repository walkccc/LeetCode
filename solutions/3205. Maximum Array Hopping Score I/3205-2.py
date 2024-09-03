class Solution:
  def maxScore(self, nums: list[int]) -> int:
    # The optimal next step is the highest number in the remaining suffix.
    return sum(itertools.accumulate(nums[:0:-1], max))
