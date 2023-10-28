class Solution:
  def countWays(self, nums: List[int]) -> int:
    return sum(a < i < b
               for i, (a, b) in  # i := # of selected nums
               enumerate(itertools.pairwise([-1] + sorted(nums) + [math.inf])))
