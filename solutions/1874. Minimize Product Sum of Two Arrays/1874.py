class Solution:
  def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
    return sum([a * b for a, b in zip(sorted(nums1), sorted(nums2, reverse=True))])
