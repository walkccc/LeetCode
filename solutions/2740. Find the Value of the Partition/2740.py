class Solution:
  def findValueOfPartition(self, nums: list[int]) -> int:
    return min(b - a for a, b in itertools.pairwise(sorted(nums)))
