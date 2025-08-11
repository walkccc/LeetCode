class Solution:
  def maxScore(self, nums: list[int]) -> int:
    summ = sum(nums)
    if len(nums) % 2 == 1:
      return summ - min(nums)
    return summ - min(a + b for a, b in itertools.pairwise(nums))
