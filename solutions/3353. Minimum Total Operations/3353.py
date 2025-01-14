class Solution:
  def minOperations(self, nums: list[int]) -> int:
    return sum(a != b for a, b in itertools.pairwise(nums))
