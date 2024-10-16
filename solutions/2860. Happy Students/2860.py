class Solution:
  def countWays(self, nums: list[int]) -> int:
    return sum(a < i < b
               for i, (a, b) in  # i := the number of the selected numbers
               enumerate(itertools.pairwise([-1] + sorted(nums) + [math.inf])))
