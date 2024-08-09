class Solution:
  def findValueOfPartition(self, nums: List[int]) -> int:
    return min(b - a for a, b in itertools.pairwise(sorted(nums)))
