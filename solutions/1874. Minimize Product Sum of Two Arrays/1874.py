class Solution:
  def minProductSum(self, nums1: list[int], nums2: list[int]) -> int:
    return sum([a * b for a, b in zip(sorted(nums1), sorted(nums2, reverse=True))])
