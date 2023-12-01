class Solution:
  def canSplitArray(self, nums: List[int], m: int) -> bool:
    return len(nums) < 3 or any(a + b >= m for a, b in itertools.pairwise(nums))
